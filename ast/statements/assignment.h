#pragma once

#include "../node.h"

class AssignmentStatement : public Node {
  protected:
    Node *left, *right;

  public:
    inline bool can_err() { return true; }

    AssignmentStatement(Node* left, Node* right, Sloc sloc) : left(left), right(right), base(sloc, "assignment") {
      this->left->parent = this;
      this->right->parent = this;
    };

    Value* q_visit() {
      /* Object fields and array members can be created on the left-hand side */
      if(left->name == "object reference") ((ObjectReference*) left)->can_create = true;
      if(left->name == "array subscript")  ((ArraySubscript*)  left)->can_create = true;

      auto rval = right->visit();
      if(!rval->written) set_error(new NoValueError(rval->name, &sloc));

      auto lval = left->visit();
      if(!lval->declared) {
        set_error(new UndeclaredVariableError(lval->name, &sloc));
        lval = SYMTAB.add(lval->name, new Value());
      }

      *lval = *rval;
      lval->set_written_declared(true, true);

      return lval;
    }
};
