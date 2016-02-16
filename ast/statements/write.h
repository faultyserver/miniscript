#pragma once

#include "../node.h"
#include "../lists/expression_list.h"

class WriteStatement : public Node {
  protected:
    ExpressionList* expressions;

  public:
    inline bool can_err() { return true; }

    WriteStatement(ExpressionList* exprs, Sloc sloc) : expressions(exprs), base(sloc, "write") {
      this->expressions->parent = this;
    };

    Value* q_visit() {
      expressions->each([this](Node* node) {
        /* Apparently, expressions in a write statement count as first-class statements...
            so, simply clear the error cache for this statement every time. */
        this->error = NULL;

        auto value = node->visit();
        if(!value->written) node->set_error(new NoValueError(value->name, &node->sloc));

        /* Piazza @158: Objects can not be directly written. */
        if(value->type == Type::OBJECT || value->type == Type::ARRAY)
          node->set_error(new TypeViolationError(&node->sloc));

        auto text = value->to_str();
        if(text == "<br />") printf("\n");
        else printf("%s", text.c_str());
      });

      return new Value();
    }
};
