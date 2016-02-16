#pragma once

#include "../node.h"

class IfStatement : public Node {
  protected:
    Node* condition;
    StatementList* body;
    Node* else_block;

  public:
    inline bool can_err() { return true; }

    IfStatement(Node* condition, StatementList* body, Node* else_block, Sloc sloc) :
      condition(condition), body(body), else_block(else_block), base(sloc, "if") {
        this->condition->parent = this;
        this->body->parent = this;
        if(else_block) this->else_block->parent = this;
      };

    Value* q_visit() {
      auto condition_value = condition->visit();

      /* Ensure that condition has a value */
      if(!condition_value->written) {
        set_error(new NoValueError(condition_value->name, &sloc));
        /* Nothing more gets evaluated */
        return new Value();

      /* Also throw an error if the condition becomes undefined */
      } else if(condition_value->type == Type::UNDEF) {
        set_error(new ConditionUnknownError(&sloc));
        /* Nothing more gets evaluated */
        return new Value();

      /* Only simple types are allowed in an RHS */
      } else if(condition_value->type != Type::NUMBER && condition_value->type != Type::STRING && condition_value->type != Type::BOOLEAN) {
        set_error(new TypeViolationError(&sloc));
        /* Nothing more gets evaluated */
        return new Value();
      }


      /* Evaluate the condition and execuate the appropriate branch */
      Value* val = new Value();
      if(condition_value->to_bool()) val = body->visit();
      else if(else_block) val = else_block->visit();

      /* Return the last value */
      return val;
    }
};
