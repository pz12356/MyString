#include "MyString.h"
#include <cstring>
#include <ostream>

MyString::MyString() : _data(nullptr), _size(0) {}
MyString::~MyString() {
  std::cout << "~MyString() " << (_data ? _data : "nullptr")
            << "\n"; // 输出 _data 的值
  delete[] _data;
}

MyString::MyString(const char *str) {
  if (str == nullptr) {
    return;
  }
  _size = strlen(str);
  _data = new char[_size + 1];
  strcpy(_data, str);
  _data[_size] = '\0';
}

MyString::MyString(const MyString &rhs) {
  if (rhs._data == nullptr) {
    _size = 0;
    _data = nullptr;
    return;
  }
  _size = rhs.size();
  _data = new char[_size + 1];
  strcpy(_data, rhs._data);
  _data[_size] = '\0';
}

MyString::MyString(MyString &&rhs) {
  _data = rhs._data;
  _size = rhs._size;
  rhs._size = 0;
  rhs._data = nullptr;
}

MyString &MyString::operator=(const MyString &rhs) {
  if (this == &rhs) {
    return *this;
  }
  if (rhs._data == nullptr) {
    _size = 0;
    _data = nullptr;
    return *this;
  }
  delete[] _data;
  _size = rhs._size;
  _data = new char[_size + 1];
  strcpy(_data, rhs._data);
  _data[_size] = '\0';
  return *this;
}

MyString MyString::operator+(const MyString &rhs) {
  if (rhs._data == nullptr) {
    return *this;
  }
  char *_temp = new char[_size + rhs._size + 1];
  strcpy(_temp, _data);
  strcat(_temp, rhs._data);
  _temp[_size + rhs._size] = '\0';
  return std::move(MyString(_temp));
}

MyString &MyString::operator+=(const MyString &rhs) {
  if (rhs._data == nullptr) {
    return *this;
  }
  _size += rhs._size;
  char *_temp = new char[_size + 1];
  strcpy(_temp, _data);
  strcat(_temp, rhs._data);
  _temp[_size] = '\0';
  delete[] _data;
  _data = _temp;
  return *this;
}

bool MyString::operator==(const MyString &rhs) const {
  if (rhs._data == nullptr) {
    return _data == nullptr;
  }
  return strcmp(_data, rhs._data) == 0;
}

std::ostream &operator<<(std::ostream &os, const MyString &rhs) {
  return os << rhs._data;
}

size_t MyString::size() const { return _size; }