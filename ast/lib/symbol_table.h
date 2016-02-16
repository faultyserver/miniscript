#pragma once

#include <list>

#include "scope.h"

class SymbolTable {
  typedef std::list<Scope*> sym_tab_t;

  sym_tab_t _scope_list;

  public:
    SymbolTable() = default;

    /* Return a reference to the lowest-level scope entry in the table */
    Scope*& current_scope() {
      return _scope_list.front();
    }

    /* Add a new scope to the top of the table */
    void push_scope(Scope* scope) {
      _scope_list.push_front(scope);
    }

    /* Remove and return the top scope from the table */
    Scope* pop_scope() {
      auto popped = _scope_list.front();
      _scope_list.pop_front();
      return popped;
    }

    /* Search the table for the lowest-level entry with the given name */
    Value* find(std::string name) {
      for(auto& scope : _scope_list) {
        auto entry = (*scope)[name];
        if(entry) return entry;
      }

      return NULL;
    }

    /* Add the given entry to the top sope of the table */
    Value* add(std::string name, Value* val) {
      auto scope = current_scope();
      scope->add(name, val);
      return (*scope)[name];
    }

    /* Either set an existing entry to the given value, or
        add it to the top scope of the table */
    Value* set(std::string name, Value* val) {
      auto entry = find(name);
      if(entry) *entry = *val;
      else entry = add(name, val);
      return entry;
    }

    /* Debug the symbol table by printing out all entries in each
        scope on the stack in a top-down fashion */
    void print() {
      for(auto& scope : _scope_list) {
        printf("Scope %s:\n", scope->name.c_str());
        scope->each([](std::string name, Value* val) {
          printf("\t%10s : %-10s\n", name.c_str(), val->to_str().c_str());
        });
      }
    }

    /* Return the symbol table itself */
    sym_tab_t get_table() { return _scope_list; }
};
