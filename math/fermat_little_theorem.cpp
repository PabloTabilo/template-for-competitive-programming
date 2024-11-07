#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pii = pair<int,int>;
 
const int M = 1e9 + 7;

// Modular inverse

ll mod_exp(ll x, ll y, ll mod){
    ll res = 1;
    while(y > 0){
	if(y % 2 == 1){
	    res = (res * x) % mod;
	}
	x = (x * x) % mod;
	y /= 2;
    }
    return res;
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
	P = ( P * mod_exp(2, M-2, M) ) % M;
	ll Q = (1LL * n * (n - 1) / 2) % M;
	
	ll Q_inv = mod_exp(Q, M-2, M);
	
	ll ans = (P * Q_inv) % M;
 
	cout << ans << endl;
    }
    return 0;
}
 
