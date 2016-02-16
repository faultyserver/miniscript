#pragma once

#include "../node.h"

class BooleanLiteral : public Node {
  protected:
    Value* val;

  public:
    BooleanLiteral(bool b, Sloc sloc) : val(new Value(b)), base(sloc, "boolean literal") {};

    Value* q_visit() {
      return val;
    };
};
