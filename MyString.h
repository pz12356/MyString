#ifndef MYSTRING_H
#define MYSTRING_H

#include <cstddef>
#include <iostream>

class MyString {
private:
  char *_data;
  size_t _size;

public:
  MyString();
  MyString(const char *str);
  MyString(const MyString &rhs);
  MyString(MyString&& rhs);
  ~MyString();

  MyString& operator=(const MyString& rhs);
  MyString& operator+=(const MyString& rhs);
  MyString operator+(const MyString& rhs);
  bool operator==(const MyString& rhs) const;
  friend std::ostream& operator<<(std::ostream& os, const MyString& rhs);

  size_t size() const;
};

#endif