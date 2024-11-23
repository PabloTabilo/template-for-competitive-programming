# Template C++ DS & Algo implementations
Various algorithm and data structure implementations that I discover while participating in contests or solving problems.

## Table of Contents
- [Math Problems](#math-problems)
- [Searching and Sorting Problems](#searching-and-sorting-problems)
- [Data Structures Problems](#data-structures-problems)
- [Strings Problems](#strings)

# Math problems
## Modular Exponentiation
We need use this technique, but it's not the complete concept to understand the problem:
* https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-ii/description/
### Fermat's Little Theorem
If $p$ is a prime number and $a$ is an integer such that $a$ is not divisible by $p$, then:

$$a^{p-1} \equiv 1 \pmod{p}$$

#### Modular Inverse using Fermat's Little Theorem
The above theorem can be rearranged to give the modular inverse of $a$:

$$a^{-1} \equiv a^{p-2} \pmod(p)$$

This allows us to calculate the inverse of $a$ under modulo $p$, which is useful for division in modular arithmetic.
Example problem for use this technique: https://codeforces.com/contest/2008/problem/F

# Searching and Sorting problems
## Intervals
* https://cses.fi/problemset/task/1619

# Data Structures Problems
## Union and Find
* https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/description/

## Segment Tree
### booleans data
* https://leetcode.com/problems/special-array-ii/description/
### sum subsequence with a condition
* https://leetcode.com/problems/maximum-sum-of-subsequence-with-non-adjacent-elements/description/

## Graph Problems
### Number nodes of max cycle vs two-component cycle + list from each node
* https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/description/

# Strings
## z-function:
* https://cp-algorithms.com/string/z-function.html
* https://judge.yosupo.jp/problem/zalgorithm

# TODO
* Implement update for segment Tree
* query from leaf nodes
