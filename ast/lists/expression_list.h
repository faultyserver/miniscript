#pragma once

#include <vector>

#include "../node.h"

class ExpressionList : public Node {
  protected:
    std::vector<Node*> _list;

  public:
    ExpressionList(Sloc sloc) : base(sloc, "expression list") {};

    Value* q_visit() {
      for(auto& expr : _list) expr->visit();
      return NULL;
    };

    void add_child(Node* child) {
      child->parent = this;
      _list.push_back(child);
    }

    void each(std::function<void(Node*)> f) {
      for(Node*& n : _list) f(n);
    };
};
