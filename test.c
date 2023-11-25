#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <CUnit/TestDB.h>

#include "gcd.h"

typedef long long (*gcd_func_t)(long long, long long);

void test_euclidean_gcd(void);
void test_euclidean_gcd_recursive(void);
void test_binary_gcd(void);
void test_binary_gcd_with_builtin_ctz(void);
void test_gcd_func(gcd_func_t);

const long long test_cases[][3] = {
#include "test_cases.txt" // 3000 test cases
};
const int len = sizeof(test_cases) / sizeof(test_cases[0]);

int main(void) {
   int ret;
   CU_pSuite suite;
   CU_initialize_registry();

   suite = CU_add_suite("GCD Tests", NULL, NULL);
   CU_add_test(suite, "Euclidean Algorithm Test", test_euclidean_gcd);
   CU_add_test(suite, "Euclidean Algorithm Recursive Test", test_euclidean_gcd_recursive);
   CU_add_test(suite, "Binary GCD Test", test_binary_gcd);
   CU_add_test(suite, "Binary GCD with builtin ctz Test", test_binary_gcd_with_builtin_ctz);

   CU_basic_run_tests();
   ret = CU_get_number_of_failures();
   CU_cleanup_registry();
   return ret;
}

void test_euclidean_gcd(void) {
   test_gcd_func(euclidean_gcd);
   return;
}

void test_euclidean_gcd_recursive(void) {
   test_gcd_func(euclidean_gcd_recursive);
   return;
}

void test_binary_gcd(void) {
   test_gcd_func(binary_gcd);
   return;
}

void test_binary_gcd_with_builtin_ctz(void) {
   test_gcd_func(binary_gcd_with_builtin_ctz);
   return;
}

void test_gcd_func(const gcd_func_t gcd_func) {
   for (int i = 0; i < len; ++i) {
      CU_ASSERT_EQUAL(gcd_func(test_cases[i][0], test_cases[i][1]), test_cases[i][2]);
   }
   return;
}
