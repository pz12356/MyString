#include "Test_MyString.h"

#include <iostream>

int main(int, char **) {
  TEST_CASE(A_string_constuctors);
  TEST_CASE(A_string_copy_operations);
  TEST_CASE(A_string_move_operations);
  TEST_CASE(A_string_management);
  TEST_CASE(A_string_append);
  TEST_CASE(A_string_comparison);
  TEST_CASE(A_string_edges_cases);
  TEST_CASE(A_string_exception_safety);

  std::cout << "All test passed." << std::endl;
  return 0;
}
