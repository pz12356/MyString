#include "MyString.h"
#include <iostream>

int main(int, char **) {
  MyString s1("Hello");
  MyString s2 = "World";
  MyString s3 = s1 + s2;
  std::cout << "s1: " << s1 << " " << s1.size() << "\n";
  std::cout << "s2: " << s2 << " " << s2.size() << "\n";
  std::cout << "s3: " << s3 << " " << s3.size() << "\n";
  return 0;
}
