#pragma once

class Value;

#include <unordered_map>

class Scope {
  protected:
    typedef std::unordered_map<std::string, Value*> scope_t;

    scope_t _scope;

  public:
    /* For debugging; each scope can be given a name to better
        identify it in the symbol table */
    std::string name;

    Scope(std::string name="") : name(name) {};

    /* Add a new entry to the scope */
    void add(std::string name, Value* val) {
      _scope[name] = val;
    }

    /* Remove and return the given entry from the scope */
    Value* remove(std::string name) {
      auto it = _scope.find(name);
      auto val = it->second;

      _scope.erase(it);
      return val;
    }

    /* Find the value WITHOUT emplacing a new one if it is not present. */
    Value*& operator[](std::string name) {
      return _scope[name];
    }

    /* C++ is more fun with blocks */
    template<typename Func>
    void each(Func f) {
      for(auto& entry : _scope)
        f(entry.first, entry.second);
    }

    /* The number of entries in the scope */
    size_t size() {
      return _scope.size();
    }
};
