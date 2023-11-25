import argparse
from math import gcd
from random import choices

N = 2000
FILE_NAME = 'test_cases.txt'
SMALL_RANGE = range(1, 1000+1)
MID_RANGE = range(1, 10**5+1)
BIG_RANGE = range(1, 10**10+1)
RANGES = [SMALL_RANGE, MID_RANGE, BIG_RANGE]

parser = argparse.ArgumentParser()
parser.add_argument('-n', type=int, default=N)
parser.add_argument('--file-name', type=str, default=FILE_NAME)
args = parser.parse_args()

cases = []
a_already = set()
b_already = set()
for i in range(3):
    a_l = choices(RANGES[i], k=args.n//3)
    b_l = choices(RANGES[i], k=args.n//3)
    for a,b in zip(a_l, b_l):
        cases.append((a, b, gcd(a, b)))

with open(args.file_name, 'w') as f:
    for i, j, k in cases:
        f.write(f'{{{i}, {j}, {k}}},')
