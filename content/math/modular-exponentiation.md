---
title: "Modular Exponentiation"
---

# Modular Exponentiation

Imagine you need to compute a value $a^e$ where $a > 0$ and $e$ is a large positive integer. Calculating this directly can result in excessively large numbers, leading to overflow errors.

## Why Modular Exponentiation?

For example, $2^{1000}$. Calculating this value directly would involve a massive number, making it computationally infeasible.

## Algorithm
The method uses divide-and-conquer principles to reduce complexity from $O(e)$ to $O(\log e)$.

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
