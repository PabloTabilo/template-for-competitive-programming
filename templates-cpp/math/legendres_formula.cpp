#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pii = pair<int,int>;
 
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    // remember for exist a "0" >> must be a 10 or 2*5 primes
    // Legendre's formula
    int cnt = 0;
    for(int i = 5; (n/i) > 0; i *= 5){
	cnt += (n/i);
    }
    cout << cnt << endl;
    return 0;
}