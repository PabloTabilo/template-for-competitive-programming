---
title: "Legendre's Formula"
---

# Legendre's Formula

Why do we need to understand this technique?  
In the CSES Problem Set, it is part of the introductory problems and serves as a foundational equation for building mathematical skills.

## Problem Statement:
The original problem can be found here: [CSES Problem 1618](https://cses.fi/problemset/task/1618/).

The task is to calculate the number of trailing zeros in the factorial $n!$. For example, $20! = 2432902008176640000$, which has 4 trailing zeros.

If we analyze the pattern, it looks like this:

$$
\begin{align*}
1! &= 1 \\\\
2! &= 2 \\\\
3! &= 6 \\\\
4! &= 24 \\\\
5! &= 120 \\\\
6! &= 720 \\\\
7! &= 5040 \\\\
8! &= 40320 \\\\
9! &= 362880 \\\\
10! &= 3628800 \\\\
11! &= 39916800 \\\\
12! &= 479001600 \\\\
13! &= 6227020800 \\\\
14! &= 87178291200 \\\\
15! &= 1307674368000 \\\\
16! &= 20922789888000
\end{align*}
$$

Every multiple of 5 seems to add a trailing zero. But why does this happen?  
This is because to add a zero to any number, we need $5 \cdot 2 = 10$. Thus, every pair $(5, 2)$ contributes a trailing zero.

For instance:  
$$6! = 1 \cdot 2 \cdot 3 \cdot 4 \cdot 5 \cdot 6 = 2^4 \cdot 3^2 \cdot 5.$$

Finally, to find the number of trailing zeros, we calculate: 
$$\text{min}(x, y)$$
where:
$$
\begin{array}{l}
\bullet \ x \text{ is the number of times (or the exponent) the prime } 2 \text{ is multiplied (e.g., for } 6, \, x = 4). \\\\
\bullet \ y \text{ is the number of times (or the exponent) the prime } 5 \text{ is multiplied (e.g., for } 6, \, y = 1). \\\\
\end{array}
$$

Thus, for $6$, $\text{min}(x=4, y=1) = 1$, which is the trailing zero for this case.

Here is where **Legendre's Formula** comes in, as it provides an expression for the exponent of the largest power of a prime $p$ that divides the factorial $n!$:

$$
v_p(n!) = \sum_{i=1}^\infty \left\lfloor \frac{n}{p^i} \right\rfloor
$$

Where:
- $n$ is the factorial.
- $p$ is the prime.
- $\lfloor x \rfloor$ is the floor function.

We can simplify the formula since if $p^i > n$, then $\left\lfloor \frac{n}{p^i} \right\rfloor = 0$.  
Thus:
$$
v_p(n!) = \sum_{i=1}^L \left\lfloor \frac{n}{p^i} \right\rfloor
$$

And:
$$
L = \lfloor \log_p(n) \rfloor
$$

If we revisit $6!$, where $6! = 2^4 \cdot 3^2 \cdot 5$, we can calculate:

$$
\begin{align*}
v_2(6!) &= \sum_{i=1}^{L = \lfloor \log_2(6) \rfloor = 2} \left\lfloor \frac{6}{2^i} \right\rfloor = \left\lfloor \frac{6}{2} \right\rfloor + \left\lfloor \frac{6}{4} \right\rfloor = 3 + 1 = 4, \\\\
v_3(6!) &= \sum_{i=1}^{L = \lfloor \log_3(6) \rfloor = 1} \left\lfloor \frac{6}{3^i} \right\rfloor = \left\lfloor \frac{6}{3} \right\rfloor = 2, \\\\
v_5(6!) &= \sum_{i=1}^{L = \lfloor \log_5(6) \rfloor = 1} \left\lfloor \frac{6}{5^i} \right\rfloor = 1.
\end{align*}
$$

## Code
The time complexity is $O(\log e)$, where $e$ is the exponent, and the space complexity is $O(1)$.

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    // Remember: for a "0" to exist, there must be a 10 or 2*5 primes
    // Legendre's formula
    int cnt = 0;
    for(int i = 5; (n / i) > 0; i *= 5){
        cnt += (n / i);
    }
    cout << cnt << endl;
    return 0;
}
```


### References
* https://en.wikipedia.org/wiki/Legendre%27s_formula


