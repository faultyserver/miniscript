#pragma once

#include "error.h"

class UndeclaredVariableError : public Error {
  public:
    UndeclaredVariableError(std::string var, Sloc* sloc) : base(var + " undeclared", sloc) {};
};
