#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int a, b;
    set<pair<int, int>> h;
    for(int i=0;i<n;i++){
	cin >> a >> b;
	h.insert({a,1});
	h.insert({b+1, -1});
    }
    int ans = 1;
    int cnt = 0;
    for(auto [i, t] : h){
	cnt += t;
	//cout << "i, t = " << i << "," << t << endl;
	//cout << "cnt = " << cnt << endl;
	ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}

