#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    ll ans = LLONG_MIN;
    vector<ll>dp(n);
    for(int i=0;i<n;i++){
	cin >> dp[i];
	if(i > 0){
	    dp[i] = max(dp[i], dp[i] + dp[i-1]);
	}
	ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}

