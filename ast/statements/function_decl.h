#pragma once

#include "../node.h"
#include "../lists/parameter_list.h"
#include "../lists/statement_list.h"

class FunctionDeclaration : public Node {
  protected:
    std::string name;
    ParameterList* params;
    StatementList* body;
    Value* function = NULL;

  public:
    inline bool can_err() { return true; }

    FunctionDeclaration(std::string name, ParameterList* params, StatementList* body, Sloc sloc) :
      name(name), params(params), body(body), base(sloc, "function decl") {
        this->params->parent = this;
        this->body->parent = this;
      };

    Value* q_visit() {
      /* Avoid creating duplicates of functions */
      if(function) return function;

      body->can_return_flag = true;

      /* Create the functor object */
      std::vector<std::string> param_list;
      params->each([&param_list](std::string p) { param_list.push_back(p); });
      auto functor = new Functor(name, body, param_list);

      /* Wrap it in a value, push it to the symbol table, and return it */
      auto val = new Value(functor, name);
      /* Function re-declarations are illegal and only the first is kept. */
      if(SYMTAB.find(name)) set_error(new TypeViolationError(&sloc));
      else function = SYMTAB.set(name, val);
      return function;
    }
};
