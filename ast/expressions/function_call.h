#pragma once

#include <vector>

#include "../node.h"
#include "../lists/expression_list.h"


class FunctionCall : public Node {
  protected:
    std::string name;
    Node* function_ref;
    ExpressionList* args;

  public:
    FunctionCall(Node* func_ref, ExpressionList* args, Sloc sloc) : function_ref(func_ref), args(args), base(sloc, "function call") {
      this->function_ref->parent = this;
      this->args->parent = this;
    };

    Value* q_visit() {
      /* Get the function object from the node */
      auto functor_ref = function_ref->visit();
      if(functor_ref->type != Type::FUNCTOR) {
        set_error(new TypeViolationError(&sloc));
        return new Value();
      }

      /* Evaluate the arguments left-to-right, and push them to a vector */
      std::vector<Value*> arguments;
      args->each([&arguments](Node* arg_expr) {
        auto val = arg_expr->visit();
        /* No matter what, these values are written and declared */
        val->set_written_declared(true, true);

        arguments.push_back(val);
      });

      /* Push the local function scope */
      SYMTAB.push_scope(new Scope());

      /* Execute the function given the arguments vector. The function's
          statement list will take care of pushing a scope to the stack. */
      auto functor = functor_ref->get_functor()->instance_for(this);
      Value* return_value = (*functor)(arguments);

      /* Pop the local function scope */
      SYMTAB.pop_scope();

      /* Return the value from the function */
      return return_value;
    };
};
