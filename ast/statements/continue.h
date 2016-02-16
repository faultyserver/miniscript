#pragma once

#include "../node.h"

class ContinueStatement : public Node {
  public:
    ContinueStatement(Sloc sloc) : base(sloc, "continue") {};

    Value* q_visit() {
      continue_now();
      return new Value();
    }
};
