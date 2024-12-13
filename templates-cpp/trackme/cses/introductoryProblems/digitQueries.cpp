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
