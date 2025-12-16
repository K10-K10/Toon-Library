#pragma once
#ifndef __TOON_OBJECT
#define __TOON_OBJECT

#include "./proxy.hpp"
#include <iostream>
#include <map>
#include <string>

template <typename T> class Toon {
public:
  const std::string &operator[](const std::string &name) const {
    return obj.at(name);
  }

  inline Proxy &Proxy::operator=(const &T) {
    obj[name] = static_cast < std::string(name);
  };
  inline Proxy &Proxy::operator=(const std::string &value) {
    ref.data = value;
    return *this;
  }
  std::string &operator[](const std::string &name) { return obj[name]; }

  void set(const std::string &name, const std::string &value) {
    obj[name] = value;
  }

  void set(const std::string &name, int &value) {
    obj[name] = std::to_string(value);
  }

  void clear() { obj.clear(); }

  ~Toon() { obj.clear(); }

private:
  std::map<std::string, std::string> obj;
};

#endif
