#include "../include/MyString.h"
#include <algorithm>
#include <cstring>
#include <ostream>
#include <stdexcept>

namespace A {

const size_t string::s_min_capacity = 15;

void string::realloc_data(size_t new_cap) {
  new_cap = std::max(new_cap, s_min_capacity);
  char *new_data = new char[new_cap + 1];
  if (_size > 0) {
    memcpy(new_data, _data, _size);
  }
  new_data[_size] = '\0';
  delete[] _data;
  _data = new_data;
  _capacity = new_cap;
}

string::string() : _size(0), _capacity(s_min_capacity) {
  _data = new char[_capacity + 1];
  _data[0] = '\0';
}

string::~string() { delete[] _data; }

string::string(const char *str) {
  if (str == nullptr) {
    throw std::invalid_argument("null pointer");
  }
  _size = strlen(str);
  _capacity = std::max(_size, s_min_capacity);
  _data = new char[_capacity + 1];
  memcpy(_data, str, _size + 1);
}

string::string(const string &rhs) : _size(rhs._size), _capacity(rhs._capacity) {
  _data = new char[_capacity + 1];
  memcpy(_data, rhs._data, _size + 1);
}

string::string(string &&rhs) noexcept
    : _size(rhs._size), _capacity(rhs._capacity), _data(rhs._data) {
  rhs._data = nullptr;
  rhs._size = 0;
  rhs._capacity = 0;
}

string &string::operator=(const string &rhs) {
  if (this == &rhs) {
    return *this;
  }
  delete[] _data;
  _size = rhs._size;
  _capacity = rhs._capacity;
  _data = new char[_capacity + 1];
  memcpy(_data, rhs._data, rhs._size + 1);
  return *this;
}

string &string::operator=(string &&rhs) {
  if (this == &rhs) {
    return *this;
  }
  delete[] _data;
  _data = rhs._data;
  _size = rhs._size;
  _capacity = rhs._capacity;
  rhs._data = nullptr;
  rhs._capacity = 0;
  rhs._size = 0;
  return *this;
}

std::ostream &operator<<(std::ostream &os, const string &rhs) {
  return os << rhs._data;
}

void string::reserve(size_t new_cap) {
  if (new_cap > _capacity) {
    realloc_data(new_cap);
  }
}

void string::shrink_to_fit() {
  if (_size < _capacity) {
    realloc_data(_size);
  }
}

string &string::append(const char *str) {
  if (str == nullptr) {
    throw std::invalid_argument("null pointer");
  }
  size_t len = strlen(str);
  if (_size + len > _capacity) {
    realloc_data(_size + len);
  }
  memcpy(_data + _size, str, len);
  _size += len;
  _data[_size] = '\0';
  return *this;
}

const char *string::c_str() const noexcept { return _data; }

size_t string::size() const noexcept{ return _size; }

size_t string::capacity() const noexcept {return _capacity;}

bool string::empty() const noexcept {return _size == 0;}

string string::operator+(const string &rhs) {
  if (rhs._data == nullptr) {
    return *this;
  }
  string temp(*this);
  temp.append(rhs.c_str());
  return std::move(string(temp));
}

string &string::operator+=(const string &rhs) {
  if (rhs._data == nullptr) {
    return *this;
  }
  append(rhs.c_str());
  return *this;
}

bool string::operator==(const string &rhs) const {
  return strcmp(_data, rhs._data) == 0;
}

bool string::operator!=(const string &rhs) const {
  return strcmp(_data, rhs._data) != 0;
}

} // namespace A