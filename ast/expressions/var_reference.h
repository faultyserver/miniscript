#pragma once

#include "../node.h"

class VariableReference : public Node {
  protected:
    std::string var_name;

  public:
    VariableReference(std::string var_name, Sloc sloc) : var_name(var_name), base(sloc, "var reference") {};

    Value* q_visit() {
      auto val = SYMTAB.find(var_name);
      if(!val) {
        /* If this is on the RHS, raise a no value error */
        if(!lhs) set_error(new NoValueError(var_name, &sloc));
        val = new Value(var_name);
        val->set_written_declared(false, false);
      }

      return val;
    }
};
