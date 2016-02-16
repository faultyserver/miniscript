#pragma once

#include "../node.h"

class LogicalOpExpression : public Node {
  protected:
    Node *left, *right;
    const char* op;

  public:
    LogicalOpExpression(Node* left, const char* op, Node* right, Sloc sloc) : left(left), op(op), right(right), base(sloc, "logical op") {
      this->left->parent = this;
      this->right->parent = this;
    };

    Value* q_visit() {
      /* § 6.8-9 : Operators : Logical And - Logical Or */
      Value* val;

      /* Logical And */
      if(!strcmp(op, "&&")) {
        auto l = left->visit();

        /* Unwritten values cause a value error. */
        if(!l->written) {
          set_error(new NoValueError(l->name, &sloc));
          val = new Value();

        /* Undefined values return undefined with no error. */
        } else if(l->type == Type::UNDEF) {
          val = new Value();

        /* Non-simple types cause type violations */
        } else if(!l->is_simple_type()) {
          set_error(new TypeViolationError(&sloc));
          val = new Value();

        /* Only evaluate r if l is true */
        } else if(l->to_bool()) {
          auto r = right->visit();
          if(!r->written) {
            set_error(new NoValueError(r->name, &sloc));
            val = new Value();

          /* Undefined values return undefined with no error. */
          } else if(r->type == Type::UNDEF) {
            val = new Value();

          /* Non-simple types cause type violations */
          } else if(!r->is_simple_type()) {
            set_error(new TypeViolationError(&sloc));
            val = new Value();

          /* r is the deciding factor of the expression. */
          } else val = new Value(!!r->to_bool());

        /* If l was true, the expression is true */
        } else val = new Value(false);

      /* Logical Or */
      } else if(!strcmp(op, "||")) {
        auto l = left->visit();

        /* Unwritten values cause a value error. */
        if(!l->written) {
          set_error(new NoValueError(l->name, &sloc));
          val = new Value();

        /* Undefined values return undefined with no error. */
        } else if(l->type == Type::UNDEF) {
          val = new Value();

        /* Non-simple types cause type violations */
        } else if(!l->is_simple_type()) {
          set_error(new TypeViolationError(&sloc));
          val = new Value();

        /* Only evaluate r if l is true */
        } else if(!l->to_bool()) {
          auto r = right->visit();
          if(!r->written) {
            set_error(new NoValueError(r->name, &sloc));
            val = new Value();

          /* Undefined values return undefined with no error. */
          } else if(r->type == Type::UNDEF) {
            val = new Value();

          /* Non-simple types cause type violations */
          } else if(!r->is_simple_type()) {
            set_error(new TypeViolationError(&sloc));
            val = new Value();

          /* r is the deciding factor of the expression. */
          } else val = new Value(!!r->to_bool());

        /* If l was true, the expression is true */
        } else val = new Value(true);
      }


      // /* Piazza @154: val is undefined, but no error is reported */
      // if(l->type == Type::UNDEF || r->type == Type::UNDEF) {
      //   /* Nothing happens */
      //   val = new Value();

      // /* Both operands MUST be convertible to boolean values */
      // } else if(!l->is_simple_type() || !r->is_simple_type()) {
      //   set_error(new TypeViolationError(&sloc));
      //   val = new Value();

      // } else {
      //   if(!strcmp(op, "&&"))       val = new Value(l->to_bool() && r->to_bool());
      //   else if(!strcmp(op, "||"))  val = new Value(l->to_bool() || r->to_bool());
      // }

      return val;
    };
};
