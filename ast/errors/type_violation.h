#pragma once

#include "error.h"

class TypeViolationError : public Error {
  public:
    TypeViolationError(Sloc* sloc) : base("type violation", sloc) {};
};
