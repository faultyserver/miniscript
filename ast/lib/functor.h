#pragma once

class Value;

#include <string>
#include <vector>

#include "../lists/statement_list.h"

class Functor {
  public:
    std::string name;
    StatementList* body;
    std::vector<std::string> params;

    Functor(std::string name, StatementList* body, std::vector<std::string> params) : body(body), params(params) {
      /* Functions can have the same with different numbers of arguments, so
          we can encode the name to include the number of arguments. For example,
          the function `add(a,b)` would become `add$2`. */
        this->name = name + "$" + std::to_string(params.size());
    };

    /* This assumes args.size() == params.size() */
    inline Value* operator()(std::vector<Value*> args) {
      auto param_name = params.begin();
      auto param_val = args.begin();

      /* Assign the argument variables with the provided values. Using add
          ensures that entries from other scopes will not be overwritten */
      for(; param_name < params.end() && param_val < args.end(); ++param_name, ++param_val)
        SYMTAB.add(*param_name, *param_val);

      /* Reset the function body to its initial state */
      body->reset();

      /* Execute the function body and return its value. Because the function
          was executed inside of its own scope (which will no longer be on the
          stack after execution), we need to create a new copy the value to
          return. This ensures that the value will persist across scope changes. */
      auto ret_val = new Value(*body->visit());

      return ret_val;
    }

    /* Create new copies for EVERYTHING so that every function call has a clean slate to build on */
    inline Functor* instance_for(Node *parent) {
      auto func = new Functor(*this);
      func->body->parent = parent;
      return func;
    }
};
