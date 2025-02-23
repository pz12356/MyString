#ifndef TEST_MYSTRING_H
#define TEST_MYSTRING_H

void test_A_string_constuctors();
void test_A_string_copy_operations();
void test_A_string_move_operations();
void test_A_string_management();
void test_A_string_append();
void test_A_string_comparison();
void test_A_string_edges_cases();
void test_A_string_exception_safety();
void test_A_string_edges_cases();
void test_A_string_exception_safety();

#define TEST_CASE(name) \
  do { \
    std::cout << "Running test case: " << #name << "..."; \
    test_##name(); \
    std::cout << "Passed." << std::endl; \
  } while(0)

#endif