#pragma once

#include "error.h"

class NoValueError : public Error {
  public:
    NoValueError(std::string var, Sloc* sloc) : base(var + " has no value", sloc) {};
};
