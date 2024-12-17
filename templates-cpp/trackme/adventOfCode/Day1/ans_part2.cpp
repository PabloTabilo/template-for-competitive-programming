#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string line;
    vector<ll> a, b;
    while(getline(cin, line)){
	if(line.empty()) break;
	stringstream ss(line);
	ll ai, bi;
	ss >> ai >> bi;
	a.push_back(ai);
	b.push_back(bi);
    }
    ll ans = 0;
    unordered_map<ll, ll> f;
    for(auto x : a){
	f[x]++;
    }
    for(auto x : b){
	ans += (x * f[x]);
    }
    cout << ans << endl;
    return 0;
}

