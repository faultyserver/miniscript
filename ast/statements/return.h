#pragma once

#include "../node.h"

class ReturnStatement : public Node {
  protected:
    Node* value;

  public:
    /* If the expression to be returned has an error, this statement
        can be responsible for reporting it */
    inline bool can_err() { return true; }

    ReturnStatement(Node* value, Sloc sloc) : value(value), base(sloc, "return") {
      this->value->parent = this;
    };

    Value* q_visit() {
      /* Calling return in a function is the logically
          equivalent to breaking out of a loop */
      return_now(value);

      auto ret_val = value ? value->visit() : new Value();
      /* Whatever the return value is, it's written now */
      ret_val->set_written_declared(true, true);

      return ret_val;
    }
};
