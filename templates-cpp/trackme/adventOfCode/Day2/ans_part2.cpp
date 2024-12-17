#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string line;
    int ans = 0;
    while(getline(cin, line)){
	if(line.empty()) break;
	stringstream ss(line);
	int num;
	vector<int> a;
	while(ss >> num){
	    a.push_back(num);
    	}
	int n = a.size();
	for(int i=0;i<n;i++){
	    bool safe = true;
	    vector<int> t;
	    for(int j = 0; j < n; j++){
		if(i == j) continue;
		t.push_back(a[j]);
	    }
	    //cout << "t: "; for(auto x : t) cout << x << " "; cout << endl;
	    int nt = t.size();
	    int incre = 0;
	    for(int i=1;i<nt;i++){
		int x = t[i] - t[i-1];
		if(abs(x) < 1 || abs(x) > 3){
		    safe = false;
		    break;
		}
		if(incre == 0){
		    incre = x > 0 ? 1 : -1;
		}else if(incre == 1){
		    if(x < 0){
			safe = false;
			break;
		    }
		}
		// incre = -1
		else{
		    if(x > 0){
			safe = false;
			break;
		    }
		}
	    }
	    if(safe) ans++;
	    if(safe) break;
	}
    }
    cout << ans << endl;
    return 0;
}

