#pragma once

#include "../lib/sloc.h"

class Error {
  protected:
    /* A constant reference to this type */
    typedef Error base;

    /* The text to print when throwing the error */
    std::string text;

    /* The location of the error */
    Sloc* sloc;


  public:
    /* A placeholder Error */
    Error() = default;
    /* A placeholder constructor with content and location information */
    Error(std::string text, Sloc* sloc) : text(text), sloc(sloc) {};

    /* Print the error to stderr */
    virtual void raise() {
      fprintf(stderr, "Line %d, %s\n", sloc->first_line, text.c_str());
    }
};
