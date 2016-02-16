#pragma once

#include <vector>

#include "../node.h"

class StatementList : public Node {
  protected:
    std::vector<Node*> _list;
    /* To keep from having to re-evaluate function declarations,
        we can store them in a separate list. */
    std::vector<Node*> _functions;

  public:
    /* Because function calls (expressions) can be used as statements, we need
        to have a fallback for the error raising location. */
    inline bool can_err() { return true; }

    /* If an error hasn't been caught by now, throw it no matter what. */
    inline void set_error(Error* err) {
      error = err;
      error->raise();
    }

    StatementList(Sloc sloc) : base(sloc, "statement list") {};

    Value* q_visit() {
      /* Push any functions defined at this level to the scope
          before evaluating any other statements. The declaration
          node takes care of pushing it to the table. */
      for(auto& func : _functions) func->visit();

      Value* val = new Value();
      /* Evaluate the body until a return statement is reached.
          `val` will contain the expression to be returned. */
      each([this, &val](Node* stmt, bool& stop) {
        val = stmt->visit();
        if(should_return) stop = true;
      });

      /* Return the last value */
      return should_return_value ? val : new Value();
    };

    void add_child(Node* child) {
      child->parent = this;
      /* Separate function declarations from everything else */
      if(child->name == "function decl") _functions.push_back(child);
      else _list.push_back(child);
    }

    void each(std::function<void(Node*, bool&)> f) {
      bool stop = false;
      for(Node*& n : _list) if(!stop) f(n, stop);
    };
};
