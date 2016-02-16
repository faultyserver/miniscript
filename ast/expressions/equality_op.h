#pragma once

#include "../node.h"

class EqualityOpExpression : public Node {
  protected:
    Node *left, *right;
    const char* op;

  public:
    EqualityOpExpression(Node* left, const char* op, Node* right, Sloc sloc) : left(left), op(op), right(right), base(sloc, "equality op") {
      this->left->parent = this;
      this->right->parent = this;
    };

    Value* q_visit() {
      auto l = left->visit();
      if(!l->written) set_error(new NoValueError(l->name, &sloc));

      auto r = right->visit();
      if(!r->written) set_error(new NoValueError(r->name, &sloc));

      Value* val;

      /* § 6.7 : Operators : Equality */

      /* Piazza @154: val is undefined, but no error is reported */
      if(l->type == Type::UNDEF || r->type == Type::UNDEF) {
        /* Nothing happens */
        val = new Value();

      /* Otherwise, the types must match */
      } else if(l->type == r->type) {
        if(!strcmp(op, "=="))       val = new Value(*l == *r);
        else if(!strcmp(op, "!="))  val = new Value(*l != *r);

      } else {
        set_error(new TypeViolationError(&sloc));
        val = new Value();
        val->set_written_declared(true, true);
      }

      return val;
    };
};
