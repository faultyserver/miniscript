#pragma once

#include <vector>

#include "../node.h"

/* A field initializer list results in the creation of an object */
class FieldInitializerList : public Node {
  protected:
    std::vector<Node*> _list;

  public:
    FieldInitializerList(Sloc sloc) : base(sloc, "field init list") {};

    Value* q_visit() {
      auto obj = new Object();
      for(auto& field : _list) {
        auto f_val = field->visit();
        obj->add(f_val->name, f_val);
      }

      return new Value(obj);
    };

    void add_child(Node* child) {
      child->parent = this;
      _list.push_back(child);
    }

    void each(std::function<void(Node*)> f) {
      for(Node*& n : _list) f(n);
    };
};
