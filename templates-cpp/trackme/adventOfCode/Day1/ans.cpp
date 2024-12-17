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
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll ans = 0;
    int n = a.size();
    for(int i = 0; i < n; i++){
	ans += abs(a[i] - b[i]);
    }
    cout << ans << endl;
    return 0;
}

