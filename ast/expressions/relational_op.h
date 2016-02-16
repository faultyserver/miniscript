#pragma once

#include "../node.h"

class RelationalOpExpression : public Node {
  protected:
    Node *left, *right;
    const char* op;

  public:
    RelationalOpExpression(Node* left, const char* op, Node* right, Sloc sloc) : left(left), op(op), right(right), base(sloc, "relational op") {
      this->left->parent = this;
      this->right->parent = this;
    };

    Value* q_visit() {
      auto l = left->visit();
      if(!l->written) set_error(new NoValueError(l->name, &sloc));

      auto r = right->visit();
      if(!r->written) set_error(new NoValueError(r->name, &sloc));

      Value* val;

      /* § 6.6 : Operators : Relational */

      /* Piazza @154: val is undefined, but no error is reported */
      if(l->type == Type::UNDEF || r->type == Type::UNDEF) {
        /* Nothing happens */
        val = new Value();

      /* Otherwise, the types must match */
      } else if(l->type == Type::NUMBER && r->type == Type::NUMBER) {
        auto l_int = l->get_int();
        auto r_int = r->get_int();

        if(!strcmp(op, "<"))       val = new Value(l_int <  r_int);
        else if(!strcmp(op, ">"))  val = new Value(l_int >  r_int);
        else if(!strcmp(op, "<=")) val = new Value(l_int <= r_int);
        else if(!strcmp(op, ">=")) val = new Value(l_int >= r_int);

      } else {
        set_error(new TypeViolationError(&sloc));
        val = new Value();
      }

      return val;
    };
};
