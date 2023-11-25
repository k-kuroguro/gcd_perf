#ifndef GCD_H_
#define GCD_H_

int popcount(long long x);
int ntz(long long x);

long long euclidean_gcd(long long a, long long b);
long long euclidean_gcd_recursive(long long a, long long b);
long long binary_gcd(long long a, long long b);
long long binary_gcd_with_builtin_ctz(long long a, long long b);

#endif /* GCD_H_ */
