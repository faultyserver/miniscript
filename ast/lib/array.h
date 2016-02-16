#pragma once

#include <unordered_map>

#include "value.h"

class Array {
  protected:
    /* Vectors were being weird, and waste space in the case of sparse arrays. */
    std::unordered_map<int, Value*> _array;
    int size = 0;

  public:
    Array() = default;

    /* Add the given value to the array at the given position. The
        array will be expanded as necessary. */
    void add(int idx, Value* val) {
      size = idx+1;

      // Place the value
      _array[idx] = val;
    };

    /* Add the given value to the end of the array */
    void append(Value* val) {
      add(size, val);
    }

    /* Return the value from the array at the position given by idx */
    Value*& operator[](int idx) {
      return _array[idx];
    }
};
