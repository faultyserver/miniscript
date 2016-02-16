#pragma once

#include "../node.h"

class StringLiteral : public Node {
  protected:
    Value* val;

  public:
    StringLiteral(std::string str, Sloc sloc) : val(new Value(str.c_str())), base(sloc, "string literal") {};

    Value* q_visit() {
      return val;
    };
};
