#pragma once

#include "../node.h"

class BreakStatement : public Node {
  public:
    BreakStatement(Sloc sloc) : base(sloc, "break") {};

    Value* q_visit() {
      break_now();
      return new Value();
    }
};
