#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, x, a, r;
    unordered_map<int, int> h;
    bool possible = false;
    int idx = -1;
    cin >> n >> x;
    for(int i=0;i<n;i++){
	cin >> a;
	r = x - a;
	if(x == 1) break;
	if(r <= 0) continue;
	if(h.count(r) > 0){
	    idx = i + 1;
	    possible = true;
	    break;
	}
	h[a] = i + 1;
    }
    //for(auto [k, v] : h) cout << "{"<< k << "->" <<v<<"} "; cout << endl;
    if(possible){
	//cout << a << ", " << r << endl;
	cout << idx << " " << h[r] << endl; 
    }else{
	cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}

