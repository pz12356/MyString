#ifndef _MYSTRING_H
#define _MYSTRING_H

#include <cstddef>
#include <iostream>

namespace A {

class string {
private:
  static const size_t s_min_capacity;
  char *_data;
  size_t _size;
  size_t _capacity;

  void realloc_data(size_t new_cap);

public:
  string();
  string(const char *str);
  string(const string &rhs);
  string(string &&rhs) noexcept;
  ~string();

  string &operator=(const string &rhs);
  string &operator=(string &&rhs);
  friend std::ostream &operator<<(std::ostream &os, const string &rhs);

  void reserve(size_t new_cap);
  void shrink_to_fit();
  string &append(const char *str);

  const char *c_str() const noexcept;
  size_t size() const noexcept;
  size_t capacity() const noexcept;
  bool empty() const noexcept;

  string operator+(const string &rhs);
  string &operator+=(const string &rhs);
  bool operator==(const string &rhs) const;
  bool operator!=(const string &rhs) const;
};

} // namespace A
#endif