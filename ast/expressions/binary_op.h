#pragma once

#include <string>

#include "../node.h"

class BinaryOpExpression : public Node {
  protected:
    Node *left, *right;
    const char* op;

  public:
    BinaryOpExpression(Node* left, const char* op, Node* right, Sloc sloc) : left(left), op(op), right(right), base(sloc, "binary op") {
      this->left->parent = this;
      this->right->parent = this;
    };

    Value* q_visit() {
      auto l = left->visit();
      if(!l->written) set_error(new NoValueError(l->name, &sloc));

      auto r = right->visit();
      if(!r->written) set_error(new NoValueError(r->name, &sloc));

      Value* val;

      /* § 6.4-5 : Operators : Multiplicative - Additive */

      /* Piazza @154: val is undefined, but no error is reported */
      if(l->type == Type::UNDEF || r->type == Type::UNDEF) {
        /* Nothing happens */
        val = new Value();

      /* tNUM op tNUM */
      } else if(l->type == Type::NUMBER && r->type == Type::NUMBER) {
        if(!strcmp(op, "+"))      val = new Value(l->get_int() + r->get_int());
        else if(!strcmp(op, "-")) val = new Value(l->get_int() - r->get_int());
        else if(!strcmp(op, "*")) val = new Value(l->get_int() * r->get_int());
        else if(!strcmp(op, "/")) val = new Value(l->get_int() / r->get_int());

      /* tSTR + tSTR */
      } else if(l->type == Type::STRING && r->type == Type::STRING && !strcmp(op, "+")) {
        std::string l_str = l->get_str();
        std::string r_str = r->get_str();
        std::string res = l_str + r_str;
        val = new Value(res.c_str());

      /* Variable types must match if both are defined */
      } else if(l->type != r->type) {
        set_error(new TypeViolationError(&sloc));
        val = new Value();

      /* Anything else is an error */
      } else {
        set_error(new TypeViolationError(&sloc));
        val = new Value();
      }


      return val;
    };
};
