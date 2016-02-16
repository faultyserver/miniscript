#pragma once

#include <vector>

#include "../node.h"

class ParameterList : public Node {
  protected:
    std::vector<std::string> _list;

  public:
    ParameterList(Sloc sloc) : base(sloc, "expression list") {};

    Value* q_visit() {
      return NULL;
    };

    void add_child(std::string child) {
      _list.push_back(child);
    }

    void each(std::function<void(std::string)> f) {
      for(std::string& n : _list) f(n);
    };
};
