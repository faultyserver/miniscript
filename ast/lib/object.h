#pragma once

#include "scope.h"

class Object : public Scope {
  /* An object is really just a scope that exists separate from (or nested
    within) the symbol table.

    This class exists mainly as a wrapper such that specialized functions
    can be added without messing up the generic Scope class. */
};
