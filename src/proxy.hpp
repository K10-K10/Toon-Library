#ifndef __TOON_PROXY
#define __TOON_PTOXY

#include <string>
template <typename T> class Proxy {
public:
  Proxy operator[](const std::string &key);
  Proxy &operator=(const std::string &key);
  Proxy &operator=(const &T);
  Proxt &operator=(const &list);
  Proxy &operator=(const bool &key);
};

#endif
