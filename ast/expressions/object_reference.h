#pragma once

#include "../node.h"

class ObjectReference : public Node {
  protected:
    Node *object;
    std::string field;

  public:
    bool can_create = false;

    ObjectReference(Node* obj, std::string field, Sloc sloc) : object(obj), field(field), base(sloc, "object reference") {
      this->object->parent = this;
    };

    Value* q_visit() {
      auto obj = object->visit();

      if(!obj->written) set_error(new NoValueError(obj->name, &sloc));
      if(!obj->declared) set_error(new UndeclaredVariableError(obj->name, &sloc));

      if(obj->type != Type::OBJECT) {
        set_error(new TypeViolationError(&sloc));
        return new Value();
      }

      auto val = (*obj->get_object())[field];
      if(!val) {
        if(can_create) {
          val = new Value(field);
          obj->get_object()->add(field, val);
        } else {
          set_error(new NoValueError(obj->name + "." + field, &sloc));
          val = new Value();
          val->set_written_declared(false, true);
        }
      }

      return val;
    };
};
