#pragma once

#include "../node.h"

class FieldInitialization : public Node {
  protected:
    std::string field;
    Node* value;

  public:
    FieldInitialization(std::string field, Node* value, Sloc sloc) : field(field), value(value), base(sloc, "field initialization") {
      this->value->parent = this;
    };

    Value* q_visit() {
      auto val = value->visit();
      val->name = field;
      return val;
    };
};
