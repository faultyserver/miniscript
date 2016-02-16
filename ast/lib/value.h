#pragma once

class Object;
class Array;
class Functor;

#include <cstring>
#include <string>

#include "type_list.h"

/* Wrapping class for values */
class Value {
  protected:
    /* Storage for the different types a value can have */
    union TypedValue {
      int number;
      char* string;
      bool boolean;
      Object* object;
      Array* array;
      Functor* functor;

      explicit TypedValue() = default;
      explicit TypedValue(int num)      : number(num)  {};
      explicit TypedValue(char* str)    : string(str)  {};
      explicit TypedValue(bool boo)     : boolean(boo) {};
      explicit TypedValue(Object* obj)  : object(obj)  {};
      explicit TypedValue(Array* arr)   : array(arr)   {};
      explicit TypedValue(Functor* fun) : functor(fun) {};
    } _value;

  public:
    /* Values are both written and declared by default, purely
        for concision in most of their use cases (literals vs. variables). */
    bool written = true;
    bool declared = true;

    /* The current defined type of the value */
    Type type;

    /* Potential name of a value for use in error reporting */
    std::string name = "";

    explicit Value(std::string name="")                   : type(Type::UNDEF),   name(name)  { };
    explicit Value(int num, std::string name="")          : _value(num),         name(name), type(Type::NUMBER)  { };
    explicit Value(char* str, std::string name="")        : _value(strdup(str)), name(name), type(Type::STRING)  { };
    explicit Value(const char* str, std::string name="")  : _value(strdup(str)), name(name), type(Type::STRING)  { };
    explicit Value(bool boo, std::string name="")         : _value(boo),         name(name), type(Type::BOOLEAN) { };
    explicit Value(Object* obj, std::string name="")      : _value(obj),         name(name), type(Type::OBJECT)  { };
    explicit Value(Array* arr, std::string name="")       : _value(arr),         name(name), type(Type::ARRAY)   { };
    explicit Value(Functor* fun, std::string name="")     : _value(fun),         name(name), type(Type::FUNCTOR) { };

    /* Explicitly set the written and declared states of the value */
    void set_written_declared(bool w=true, bool d=true) {
      written = w;
      declared = d;
    };

    /* Whether or not the given value is a simple type */
    bool is_simple_type() {
      return type == Type::NUMBER || type == Type::STRING || type == Type::BOOLEAN;
    }


    /* Convert the current value to its string representation */
    std::string to_str() {
      std::string str = "undefined";
      switch(type) {
        case Type::NUMBER:
          str = std::to_string(_value.number);
          break;

        case Type::BOOLEAN:
          str = _value.boolean ? "true" : "false";
          break;

        case Type::STRING:
          str = _value.string;
          break;

        case Type::ARRAY:
        case Type::OBJECT:
        case Type::FUNCTOR:
        case Type::UNDEF:
          str = "undefined";
          break;
      }

      return str;
    }

    /* Convert the current value to its "boolean" representation. If the conversion
        is considered "illegal", return a negative number. */
    int to_bool() {
      int result;
      switch(type) {
        case Type::NUMBER:
          result = _value.number;
          break;

        case Type::BOOLEAN:
          result = _value.boolean;
          break;

        case Type::STRING:
          result = strcmp(_value.string, "") != 0;
          break;

        case Type::ARRAY:
        case Type::OBJECT:
        case Type::FUNCTOR:
        case Type::UNDEF:
          result = 0;
      }

      return result;
    }


    /* Pass-through access to the data struct */
    int get_int()           { return _value.number;  }
    char* get_str()         { return _value.string;  }
    bool get_bool()         { return _value.boolean; }
    Object* get_object()    { return _value.object;  }
    Array* get_array()      { return _value.array;   }
    Functor* get_functor()  { return _value.functor; }


    inline bool operator==(const Value& rhs) {
      if(type != rhs.type) return false;
      switch(type) {
        case Type::NUMBER:
          return _value.number == rhs._value.number;

        case Type::STRING:
          return !strcmp(_value.string, rhs._value.string);

        case Type::BOOLEAN:
          return _value.boolean == rhs._value.boolean;

        case Type::OBJECT:
        case Type::ARRAY:
        case Type::FUNCTOR:
        case Type::UNDEF:
          return false;
      }
    }

    inline bool operator!=(const Value& rhs) { return !(*this == rhs); }
};
