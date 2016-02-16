#pragma once

#include "error.h"

class ConditionUnknownError : public Error {
  public:
    ConditionUnknownError(Sloc* sloc) : base("condition unknown", sloc) {};
};
