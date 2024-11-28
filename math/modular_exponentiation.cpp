#include<bits/stdc++.h>

using namespace std;

// fast calculation of a^b without OVERFLOW, where a is a integer and b is a big integer
// the mod is the module val for evit the overflow problem
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

int main(){
    int MOD = 1e9 + 7;
    // modular arithmetic : x*y = z >> ((x%mod) * (y%mod) ) % mod = z % mod;
    int res = ((c % MOD) * modularExponentiation(a, b, mod)) % MOD;
    cout << c * modularExponentiation(a, b, MOD) << endl;
}