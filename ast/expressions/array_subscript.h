#pragma once

#include "../node.h"

class ArraySubscript : public Node {
  protected:
    Node *array, *index;

  public:
    bool can_create = false;

    ArraySubscript(Node* arr, Node* idx, Sloc sloc) : array(arr), index(idx), base(sloc, "array subscript") {
      this->array->parent = this;
      this->index->parent = this;
    };

    Value* q_visit() {
      auto idx = index->visit();
      auto arr = array->visit();

      if(!arr->written) set_error(new NoValueError(arr->name, &sloc));
      if(!arr->declared) set_error(new UndeclaredVariableError(arr->name, &sloc));

      /* Ensure the access is semantically valid */
      if(arr->type != Type::ARRAY || idx->type != Type::NUMBER) {
        set_error(new TypeViolationError(&sloc));
        return new Value();
      }

      auto val = (*arr->get_array())[idx->get_int()];
      if(!val) {
        if(can_create) {
          val = new Value();
          arr->get_array()->add(idx->get_int(), val);
        } else {
          set_error(new NoValueError(arr->name + "[" + idx->to_str() + "]", &sloc));
          val = new Value();
          val->set_written_declared(false, true);
        }
      }

      return val;
    };
};
