#include "gcd.h"

int popcount(long long x) {
   x = (x & 0x55555555) + (x >> 1 & 0x55555555);
   x = (x & 0x33333333) + (x >> 2 & 0x33333333);
   x = (x & 0x0f0f0f0f) + (x >> 4 & 0x0f0f0f0f);
   x = (x & 0x00ff00ff) + (x >> 8 & 0x00ff00ff);
   return (x & 0x0000ffff) + (x >> 16 & 0x0000ffff);
}

int ctz(long long x) {
   return popcount((x & (-x)) - 1);
}

long long euclidean_gcd(long long a, long long b) {
   long long r;
   while (b) {
      r = a % b;
      a = b;
      b = r;
   }
   return a;
}

long long euclidean_gcd_recursive(long long a, long long b) {
   return b ? euclidean_gcd_recursive(b, a % b) : a;
}

long long binary_gcd(long long a, long long b) {
   int k = ctz(a | b);
   a >>= ctz(a);
   b >>= ctz(b);
   while (a != b) {
      if (a > b) {
         a -= b;
         a >>= ctz(a);
      } else {
         b -= a;
         b >>= ctz(b);
      }
   }
   return a << k;
}

long long binary_gcd_with_builtin_ctz(long long a, long long b) {
   int k = __builtin_ctzll(a | b);
   a >>= __builtin_ctzll(a);
   b >>= __builtin_ctzll(b);
   while (a != b) {
      if (a > b) {
         a -= b;
         a >>= __builtin_ctzll(a);
      } else {
         b -= a;
         b >>= __builtin_ctzll(b);
      }
   }
   return a << k;
}
