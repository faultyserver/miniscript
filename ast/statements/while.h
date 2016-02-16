#pragma once

#include "../node.h"

class WhileStatement : public Node {
  protected:
    Node* condition;
    StatementList* body;

  public:
    inline bool can_err() { return true; }
    inline bool can_flow_control() { return true; }

    WhileStatement(Node* cond, StatementList* body, Sloc sloc) : condition(cond), body(body), base(sloc, "while") {
      this->condition->parent = this;
      this->body->parent = this;
    };

    Value* q_visit() {
      Value* val = new Value();

      /* Iterate endlessly so we can control the iteration from the inside */
      while(true) {
        /* Reset the break/continue status of the loop */
        should_break = should_continue = false;

        auto condition_value = condition->visit();

        /* Stop iterating if the condition becomes undefined */
        if(condition_value->type == Type::UNDEF) {
          set_error(new ConditionUnknownError(&sloc));
          break;
        }

        /* Stop iterating if the condition becomes false */
        if(!condition_value->to_bool()) break;

        /* All else being valid, evaluate the body for this iteration */
        body->each([this, &val](Node* stmt, bool& stop) {
          val = stmt->visit();
          if(should_break || should_continue || should_return) stop = true;
        });

        if(should_break || should_return) break;
      }

      return should_return_value ? val : new Value();
    }
};
