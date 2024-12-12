#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<ll> p(n);
    for(int i=0;i<n;i++){
	cin >> p[i];
    }
    unordered_map<int, ll> asum;
    for(int mask=1;mask <= ((1 << n)-1);mask++){
	for(int i=0;i<n;i++){
	    if( mask & (1<<i) ){
		asum[mask]+=p[i];
	    }
	}
    }
    ll ans = LLONG_MAX;
    for(int mask=1;mask <= ((1 << n)-1);mask++){
	int sub2 = ((1<<n)-1) ^ mask;
	//cout << "mask = " << mask << ", sub2 = " << sub2 <<endl;
	//cout << "asum[mask] = " << asum[mask] << ", asum[sub2] = " << asum[sub2] << endl;
	ans = min(ans, abs(asum[mask] - asum[sub2]));
    }
    cout << ans << endl;
    return 0;
}

