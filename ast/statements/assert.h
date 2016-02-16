#pragma once

#include "../node.h"

class AssertStatement : public Node {
  protected:
    Node* expr;

  public:
    inline bool can_err() { return true; }

    AssertStatement(Node* expr, Sloc sloc) : expr(expr), base(sloc, "assert") {
      this->expr->parent = this;
    };

    Value* q_visit() {
      /* Abusing unimplemented features for debugging is great */
      print_stack(this);
      return new Value();
    }
};
