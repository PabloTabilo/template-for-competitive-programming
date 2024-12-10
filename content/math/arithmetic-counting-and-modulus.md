---
title: "Arithmetic, counting and modulus operations"
weight: 1
---

# Arithmetic, counting and modulus operations

In this article, we aim to enhance our pattern recognition abilities by leveraging fundamental mathematical skills such as arithmetic, counting, and modulus operations.

To begin, we will explore a problem that encourages a deeper understanding of these techniques. This problem, known as `Digit Queries`, is part of the CSES problem set.

## Digit Queries - Problem statement
Consider an infinite string that consist of all positive integer in increasing order:
`12345678910111213141516171819202122232425...`
Your task is to process $q$ queries of the form: what's the digit at position $k$ in the string?

*Constraints*
* $1 \le q \le 1000$
* $1 \le k \le 10^{18}$

For example, if a query asks for the digit at position $k = 7$, we need to return `7`. Why? Because the $7^{th}$ position in the infinite string `1234567...` is indeed `7`.

Another example: if $k = 12$, we must return `1` since the $12^{th}$ digit of the string `123456789101...` is `1`.

As a final example, consider $k = 19$. We need to return `4` because in the string `1234567891011121314...`, the $19^{th}$ digit is `4`.


## Thoughts

The string is infinite, so we cannot fully generate or store it. Instead, we need to identify patterns or make "jumps" through the sequence of digits.

If we consider the numbers grouped by their digit lengths:
* `123456789` (1-digit numbers)
* `10111213141516171819202122...9899` (2-digit numbers)
* `100101102103104...998999` (3-digit numbers)
* `...` and so forth

For each digit length $d$, the total number of digits in that block can be expressed as:

$$
block_d = 9 \cdot 10^{d-1} \cdot d
$$

For example:
* If $d = 1$, then $block_1 = 9 \cdot 10^0 \cdot 1 = 9$ digits.
* If $d = 2$, then $block_2 = 9 \cdot 10^1 \cdot 2 = 180$ digits.
* If $d = 3$, then $block_3 = 9 \cdot 10^2 \cdot 3 = 2700$ digits.

Did you see the pattern?, its like we can build some solution that runs on $O(\log_{10}(k))$.

We also know the starting point (the first number) for each block:
* If $d = 1$, then $start = 1$
* If $d = 2$, then $start = 10$
* If $d = 3$, then $start = 100$

... and so on.

With this information, we can find the specific number $num_k$ that contains the digit at position $k$:

$$
num_k = start + \frac{(k_{block_d} - 1)}{d}
$$

Here, $k_{block_d}$ is the position $k$ adjusted to the current digit block. We cannot use the raw $k^{th}$ position directly because we must first exclude all the digits from previous blocks.

For example, if $k = 19$, the first 9 digits are from the 1-digit block, leaving $k_{block_2} = 19 - 9 = 10$. Since the 2-digit block starts right after those 9 digits, we move forward within this block. We use $k_{block_2} - 1 = 9$ to determine how far into the 2-digit sequence we go, and in this case, $num_k = 14$.

After finding $num_k$, we identify the exact digit with a modulus operation:
$$
digitIndex = (k - 1) \mod d
$$

We then convert $num_k$ to a `string` and extract the character at `digitIndex`, `num_k[digitIndex]`.

## Code
```cpp
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    while(q--){
	ll k;
	cin >> k;
	ll d = 1;
	ll tot = 9 * d;
	ll ten = 1;
	while(tot < k){
	    k -= tot;
	    d++;
	    ten *= 10;
	    tot = 9 * d * ten;
	}
	// numk = 99 -> d = 2
	// nunk = 100 -> d = 3
	// k >> iam here -> d
	// floor(k-1/d)
	ll numk = ten + (k-1)/d;
	ll i = (k-1)%d;
	string s = to_string(numk);
	//cout << "k = " << k << ", ten = " << ten << endl;
	//cout << "numk = " << numk << endl;
	//cout << "i = " << i << endl;
	cout << s[i] << endl;
    }
 
    return 0;
}
```

## References
* Digit Queries problem: https://cses.fi/problemset/task/2431/