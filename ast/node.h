#pragma once

/* Allow an initializer list to represent the sloc. For example:
    { 1, 1, 10, 15 } = Line 1, Columns 10-15. */
typedef std::initializer_list<int> sloc_t;

#include <cstring>
#include <functional>
#include <vector>

#include "errors/error.h"
#include "lib/symbol_table.h"
#include "lib/sloc.h"

class Value;

class Node;

/* A static list to the current node in the tree. When a node is entered,
    it is pushed to this list. When it is exited, it is popped. */
static std::vector<Node*> locale;

class Node {
  protected:
    /* A constant reference to this type */
    typedef Node base;

  public:
    /* The name of this node type */
    std::string name = "base node";

    /* sloc information for the node */
    int
      first_line = -1,
      last_line = -1,
      first_col = -1,
      last_col = -1;

    /* Every node should be able to reference it's parent */
    Node* parent = NULL;

    /* The error instance of the first error in this node's subtree */
    Error* error = NULL;

    /* The location of the matching source code for this node */
    Sloc sloc;

    /* True if this node is explicitly on the LHS of a statement */
    bool lhs = false;

    /* Can this node throw an error itself? */
    virtual inline bool can_err() { return false; }

    /* Can this node be broken or continued? */
    virtual inline bool can_flow_control() { return false; }

    /* Can this node be returned from */
    virtual inline bool can_return() { return can_return_flag; }

    /* For flow control nodes, should it break, continue, or do nothing? */
    bool should_break = false, should_continue = false;

    /* For function nodes, should it return? Since only certain instances
        of nodes will fit this case, the flag is used instead of a constant.
        Also indicate if the function should return a value */
    bool should_return = false,
      can_return_flag = false,
      should_return_value = false;


    /* A placeholder node */
    Node(std::string name="", Node* parent=NULL) : name(name), parent(parent) {};
    /* A placeholder constructor with location information */
    Node(Sloc sloc, std::string name="", Node* parent=NULL) : name(name), parent(parent), sloc(sloc) {};

    /* Propagate error assignments up the tree, and always keep the first error. */
    virtual inline void set_error(Error* err) {
      /* One error per statement can be translated to "one error per node branch" */
      if(error) return;

      if(can_err() && !error) {
        error = err;
        error->raise();
      } else parent->set_error(err); // Purposely causes an error on NULL
    }

    /* Tell the next-lowest-level loop to break now */
    virtual inline void break_now() {
      if(should_break) return;
      if(can_flow_control()) should_break = true;
      else parent->break_now();
    }

    /* Tell the next-lowest-level loop to continue now */
    virtual inline void continue_now() {
      if(should_continue) return;
      if(can_flow_control()) should_continue = true;
      else parent->continue_now();
    }

    /* Tell the next-lowest-level function to return now */
    virtual inline void return_now(bool with_value=false) {
      /* Values need to propagate up the tree, so every node
          will have to pass the value to its parent */
      should_return_value = with_value;
      should_return = true;
      if(!can_return()) parent->return_now(with_value);
    }

    /* A wrapper around visit() to handle some housekeeping things */
    virtual Value* visit() {
      /* Add to the locale */
      locale.push_back(this);
      /* Execute the node */
      auto val = q_visit();
      /* Remove from the locale */
      locale.pop_back();

      return val;
    }

    /* visit() must be defined by *every* node */
    virtual Value* q_visit() = 0;



    /* Optional list node functions */
    virtual Value* visit_as_list() { return NULL; };
    virtual void add_child(Node* child) {};
    virtual void each(std::function<void(Node*)> f) {};

    /* Optionally-overwritable reset functionality to reset all
        runtime flags and errors to their initial state */
    virtual void reset() {
      error = NULL;
      should_break = false;
      should_continue = false;
      should_return = false;
      should_return_value = false;
    }
};

/* Print out the path from root to this node */
static void print_stack(Node* n) {
  printf("Stack trace for %s:\n", n->name.c_str());
  for(auto it = locale.begin(); it != locale.end(); ++it)
    printf("\t(%p) %10s : %s\n", *it, (*it)->sloc.to_str().c_str(), (*it)->name.c_str());
}

/* The symbol table should be global and available to every node */
static SymbolTable SYMTAB;
