# A Journey Through DS and Algorithms: With C++ Template Reference, notes and Problem Insights
Various algorithm and data structure implementations that I discover while participating in contests or solving problems.

## Table of Contents
- [Math Problems](#math-problems)
    - [Modular Exponentiation](#modular-exponentiation)
    - [Fermat's Little Theorem](#fermats-little-theorem)
- [Searching and Sorting Problems](#searching-and-sorting-problems)
- [Data Structures Problems](#data-structures-problems)
    - [DSU - Union and Find](#dsu---union-and-find)
    - [Segment Tree](#segment-tree)
    - [General Graphs](#graph-problems)
- [Strings Problems](#strings)
    - [z-function](#z-function)

# Math problems
## Modular Exponentiation
Imagine you need to compute a value $a^e$ where $a>0$ and $e$ is a large positive integer. Calculating this directly can result in excessively large numbers, leading to overflow errors. To avoid this, we use modular arithmetic, where the result is calculated modulo a given number $m$. In mathematical terms, we aim to compute:

$$a^e \mod m$$

Where:
* $a>0$ and $e>0$, both are integers.
* $m$ is the modulus, typically chosen to constrain the result within manageable bounds.
### Why Modular Exponentiation ?
For example, $2^{1000}$. Calculating this value directly would involve a massive number, making it computationally infeasible due to both time complexity and memory constraints. Modular exponentiation is a technique designed to handle this efficiently.

### The Logic behind
The method relies on divide-and-conquer principles while leveraging properties of modular arithmetic to simplify intermediate results. This approach reduces the computational complexity from $O(e)$ to $O(\log e )$, making it significantly faster.

Let’s break it down using an example: compute $2^9 \pmod{10^9 + 1}$.

We know:

$$2^9 = 2\cdot2^8 = 2\cdot(2^4)^2$$

The idea is to take advantage of the parity (odd or even nature) of the exponent.
* if $e$ is odd, $a^e = a\cdot a^{e-1}$.
* if $e$ is even, $a^e = (a^{e/2})^2$.

This recursive pattern forms the basis of the iterative implementation of modular exponentiation.

```c++
long long modularExponentiation(long long base, long long exp, long long mod){
    long long result = 1;
    while(exp > 0){
        if(exp % 2 == 1){
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
```

### Example problems

* https://cses.fi/problemset/task/1617/

We need use this technique, but it's not the complete concept to understand the problem:
* https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-ii/description/
### Fermat's Little Theorem
If $p$ is a prime number and $a$ is an integer such that $a$ is not divisible by $p$, then:

$$a^{p-1} \equiv 1 \pmod{p}$$

#### Modular Inverse using Fermat's Little Theorem
The above theorem can be rearranged to give the modular inverse of $a$:

$$a^{-1} \equiv a^{p-2} \pmod{p}$$

This allows us to calculate the inverse of $a$ under modulo $p$, which is useful for division in modular arithmetic.
Example problem for use this technique: https://codeforces.com/contest/2008/problem/F

# Searching and Sorting problems
## Intervals
* https://cses.fi/problemset/task/1619

# Data Structures Problems
## DSU - Union and Find
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
## z-function
* https://cp-algorithms.com/string/z-function.html
* https://judge.yosupo.jp/problem/zalgorithm

# TODO
* Implement update for segment Tree
* query from leaf nodes
* Implement some of combinatorics
    - https://cses.fi/problemset/task/1072
* Good problem for Legendre's formula
    - https://cses.fi/problemset/result/11293617/
    - https://en.wikipedia.org/wiki/Legendre%27s_formula
* Good problem for euclidean circuit
    - https://leetcode.com/problems/valid-arrangement-of-pairs/description/?envType=daily-question&envId=2024-11-30
    - we implement a solution using Hierholzer's algorithm
* Example of a good book online:
    - https://en.algorithmica.org/hpc/
    - https://gohugo.io/getting-started/quick-start/
    - very good theme: https://themes.gohugo.io/themes/hugo-book/
