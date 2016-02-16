#pragma once

#include <sstream>

/* Source code location tracking */
class Sloc {
  public:
    int first_line, last_line,
        first_col, last_col;

    Sloc(int fl=-1, int ll=-1, int fc=-1, int lc=-1) : first_line(fl), last_line(ll), first_col(fc), last_col(lc) {};

    std::string to_str() {
      std::stringstream ss;
      ss << first_line << "-" << last_line << ":" << first_col << "-" << last_col;
      return ss.str();
    }
};
