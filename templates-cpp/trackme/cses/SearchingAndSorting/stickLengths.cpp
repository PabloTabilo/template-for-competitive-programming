#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<ll> p(n);
    for(int i=0;i<n;i++){
	cin >> p[i];
    }
    ll l = *min_element(p.begin(), p.end());
    ll r = *max_element(p.begin(), p.end());
    ll ans = 0; // tot cost
    for(int i=0;i<n;i++){
	ans += abs(r - p[i]);
    }
    while(l <= r){
	ll mid = l + (r - l)/2;
	ll curr = 0; // current cost
	for(int i=0;i<n;i++){
	    curr += abs(mid - p[i]);
	}
	if(curr > ans){
	    l = mid + 1;
	}else{
	    cout << "mid, curr = " << mid << "," << curr << endl;
	    ans = min(ans, curr);
	    r = mid - 1;
	}
    }
    cout << ans << endl;
    return 0;
}

