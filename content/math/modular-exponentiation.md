---
title: "Modular Exponentiation"
weight: 3
---

# Modular Exponentiation

Imagine you need to compute a value $a^e$ where $a>0$ and $e$ is a large positive integer. Calculating this directly can result in excessively large numbers, leading to overflow errors. To avoid this, we use modular arithmetic, where the result is calculated modulo a given number $m$. In mathematical terms, we aim to compute:

$$a^e \mod m$$

Where:
* $a>0$ and $e>0$, both are integers.
* $m$ is the modulus, typically chosen to constrain the result within manageable bounds.
## Why Modular Exponentiation ?
For example, $2^{1000}$. Calculating this value directly would involve a massive number, making it computationally infeasible due to both time complexity and memory constraints. Modular exponentiation is a technique designed to handle this efficiently.

## The Logic behind
The method relies on divide-and-conquer principles while leveraging properties of modular arithmetic to simplify intermediate results. This approach reduces the computational complexity from $O(e)$ to $O(\log e )$, making it significantly faster.

Let’s break it down using an example: compute $2^9 \pmod{10^9 + 1}$.

We know:

$$2^9 = 2\cdot2^8 = 2\cdot(2^4)^2$$

The idea is to take advantage of the parity (odd or even nature) of the exponent.
* if $e$ is odd, $a^e = a\cdot a^{e-1}$.
* if $e$ is even, $a^e = (a^{e/2})^2$.

This recursive pattern forms the basis of the iterative implementation of modular exponentiation.
## Algorithm
```cpp
long long modularExponentiation(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
```
# Example Problems
* https://cses.fi/problemset/task/1617/
* We need use this technique, but it's not the complete concept to understand the problem: https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-ii/description/
