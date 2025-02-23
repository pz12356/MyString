#include "../include/MyString.h"
#include <cassert>
#include <cstring>

void test_A_string_constuctors() {
  A::string s1;
  assert(s1.empty());
  assert(s1.size() == 0);
  assert(s1.capacity() == 15);
  assert(s1.c_str()[0] == '\0');

  A::string s2("hello");
  assert(s2.size() == 5);
  assert(s2.capacity() == 15);
  assert(s2.c_str()[5] == '\0');
  assert(strcmp(s2.c_str(), "hello") == 0);
}

void test_A_string_copy_operations() {
  A::string s1("hello");

  A::string s2(s1);
  assert(strcmp(s2.c_str(), "hello") == 0);
  assert(s2.c_str() != s1.c_str());

  A::string s3;
  s3 = s1;
  assert(strcmp(s3.c_str(), "hello") == 0);
  assert(s1.c_str() != s3.c_str());
}

void test_A_string_move_operations() {
  A::string s1("Hello");
  const char *original_data = s1.c_str();
  A::string s2(std::move(s1));

  assert(s2.c_str() == original_data);
  assert(s1.empty());
  assert(s1.c_str() == nullptr);

  A::string s3;
  s3 = std::move(s2);
  assert(s3.c_str() == original_data);
  assert(s2.empty());
  assert(s2.c_str() == nullptr);
}

void test_A_string_management() {
  A::string s;
  assert(s.capacity() == 15);

  s.reserve(20);
  assert(s.capacity() >= 20);

  s.shrink_to_fit();
  assert(s.capacity() == 15);
}

void test_A_string_append() {
  A::string s1;
  s1.append("Hello");
  assert(strcmp(s1.c_str(), "Hello") == 0);

  s1.append(" World");
  assert(strcmp(s1.c_str(), "Hello World") == 0);

  A::string s2("Hello");
  A::string s3(" World");
  A::string s4 = s2 + s3;
  assert(strcmp(s4.c_str(), "Hello World") == 0);
  assert(strcmp(s2.c_str(), "Hello") == 0);
  assert(strcmp(s3.c_str(), " World") == 0);
  s2 += s3;
  assert(strcmp(s3.c_str(), " World") == 0);
  assert(strcmp(s2.c_str(), "Hello World") == 0);
}

void test_A_string_comparison() {
  A::string s1("Hello");
  A::string s2("Hello");
  A::string s3("World");

  assert(s1 == s2);
  assert(s1 != s3);
}

void test_A_string_edges_cases() {
  A::string s1("");
  assert(s1.size() == 0);
  assert(s1.c_str()[0] == '\0');

  std::string long_str(1000, 'x');
  A::string s2(long_str.c_str());
  assert(s2.size() == 1000);
  assert(strcmp(s2.c_str(), long_str.c_str()) == 0);
}

void test_A_string_exception_safety() {
  try {
    A::string s1(nullptr);
    assert(false);
  } catch (const std::invalid_argument &e) {
  }

  try {
    A::string s1;
    s1.append(nullptr);
    assert(false);
  } catch (const std::invalid_argument &e) {
  }
}