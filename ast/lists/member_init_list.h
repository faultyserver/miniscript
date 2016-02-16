#pragma once

#include <vector>

#include "../node.h"

/* A member initializer list results in the creation of an array */
class MemberInitializerList : public Node {
  protected:
    std::vector<Node*> _list;

  public:
    MemberInitializerList(Sloc sloc) : base(sloc, "member init list") {};

    Value* q_visit() {
      auto arr = new Array();
      for(auto& member : _list)
        arr->append(member->visit());

      return new Value(arr);
    };

    void add_child(Node* child) {
      child->parent = this;
      _list.push_back(child);
    }

    void each(std::function<void(Node*)> f) {
      for(Node*& n : _list) f(n);
    };
};
