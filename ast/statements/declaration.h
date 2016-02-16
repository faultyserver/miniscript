#pragma once

#include "../node.h"

class DeclarationStatement : public Node {
  protected:
    std::string name;

  public:
    inline bool can_err() { return true; }

    DeclarationStatement(std::string name, Sloc sloc) : name(name), base(sloc, "declaration") {};

    Value* q_visit() {
      auto val = SYMTAB.add(name, new Value(name));
      val->set_written_declared(false, true);
      return val;
    }
};
