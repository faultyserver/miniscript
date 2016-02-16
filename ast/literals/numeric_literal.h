#pragma once

#include "../node.h"

class NumericLiteral : public Node {
  protected:
    Value* val;

  public:
    NumericLiteral(int num, Sloc sloc) : val(new Value(num)), base(sloc, "numeric literal") {};

    Value* q_visit() {
      return val;
    };
};
