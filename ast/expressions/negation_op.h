#pragma once

#include "../node.h"

class NegationOpExpression : public Node {
  protected:
    Node* value;

  public:
    NegationOpExpression(Node* value, Sloc sloc) : value(value), base(sloc, "negation op") {
      this->value->parent = this;
    };

    Value* q_visit() {
      /* § 6.3 : Operators : Negation */

      auto orig = value->visit();

      if(!orig->written) set_error(new NoValueError(orig->name, &sloc));

      int bool_val = orig->to_bool();

      Value* val = new Value();

      /* Complex types cannot be converted to booleans, but UNDEF can */
      if(orig->type == Type::UNDEF) {
        val = new Value();
      } else if(bool_val < 0) {
        set_error(new TypeViolationError(&sloc));
      } else val = new Value(!bool_val);

      return val;
    };
};
