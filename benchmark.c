#include <stdio.h>
#include <time.h>

#include "gcd.h"

typedef long long (*gcd_func_t)(long long, long long);

double measure(gcd_func_t);

const long long test_cases[][3] = {
#include "test_cases_for_benchmark.txt" // 60000 test cases
};
const int len = sizeof(test_cases) / sizeof(test_cases[0]);

int main(void) {
   printf("Euclidean Algorithm: %f s\n", measure(euclidean_gcd));
   printf("Euclidean Algorithm Recursive: %f s\n", measure(euclidean_gcd_recursive));
   printf("Binary GCD: %f s\n", measure(binary_gcd));
   printf("Binary GCD with builtin ctz: %f s\n", measure(binary_gcd_with_builtin_ctz));
   return 0;
}

double measure(gcd_func_t gcd_func) {
   clock_t start, end;
   start = clock();
   for (int i = 0; i < len; ++i) {
      gcd_func(test_cases[i][0], test_cases[i][1]);
   }
   end = clock();
   return (double)(end - start) / (double)CLOCKS_PER_SEC;
}
