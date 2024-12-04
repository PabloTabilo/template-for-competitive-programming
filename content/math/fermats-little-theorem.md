---
title: "Fermat's little Theorem"
---
# Fermat's Little Theorem

If $p$ is a prime number and $a$ is an integer such that $a$ is not divisible by $p$, then:

$$a^{p-1} \equiv 1 \pmod{p}$$

## Modular Inverse using Fermat's Little Theorem
The above theorem can be rearranged to give the modular inverse of $a$:

$$a^{-1} \equiv a^{p-2} \pmod{p}$$

This allows us to calculate the inverse of $a$ under modulo $p$, which is useful for division in modular arithmetic.
Example problem for use this technique: https://codeforces.com/contest/2008/problem/F

```cpp
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pii = pair<int,int>;
 
const int M = 1e9 + 7;

// Modular inverse

ll modularExponentiation(ll base, ll exp, ll mod){
    ll result = 1;
    while(exp > 0){
        if(exp % 2 == 1){
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
 
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
	int n;
	cin >> n;
	vector<ll> a(n);
	ll S = 0;
	for(int i = 0; i < n; i++){
	    cin >> a[i];
	    S = (S + a[i]) % M;
	}
	
	ll P = 0;
	for(int i=0;i<n;i++){
	    P = (P % M + (a[i] * (S - a[i] + M) ) % M ) % M;
	}
	P = ( P * mod_exp(2, M-2, M) ) % M; // P * 2^{-1}
	ll Q = (1LL * n * (n - 1) / 2) % M;
	
	ll Q_inv = mod_exp(Q, M-2, M); // Q^{-1}
	
	ll ans = (P * Q_inv) % M;
 
	cout << ans << endl;
    }
    return 0;
}