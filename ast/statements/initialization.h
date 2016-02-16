#pragma once

#include "../node.h"

class InitializationStatement : public Node {
  protected:
    std::string name;
    Node* value;

  public:
    inline bool can_err() { return true; }

    InitializationStatement(std::string name, Node* val, Sloc sloc) : name(name), value(val), base(sloc, "initialization") {
      this->value->parent = this;
    };

    Value* q_visit() {
      auto val = value->visit();

      if(!val->written) set_error(new NoValueError(val->name, &sloc));

      auto val_copy = new Value(*val);
      val_copy->name = name;
      val = SYMTAB.add(name, val_copy);
      val->set_written_declared(true, true);

      return val;
    }
};
