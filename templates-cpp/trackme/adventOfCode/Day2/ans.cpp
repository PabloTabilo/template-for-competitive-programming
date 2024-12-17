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
	int increasing = 0;
	bool safe = true;
	for(int i=1;i<n;i++){
	    int d = a[i] - a[i-1];
	    if(abs(d) < 1 || abs(d) > 3){
		safe = false;
		break;
	    }
	    if(increasing == 0){
		increasing = d > 0 ? 1 : -1;
	    }else{
		if(d < 0 && increasing != -1){
		    safe = false;
		    break;
		}
		if(d > 0 && increasing != 1){
		    safe = false;
		    break;
		}
	    }
	}
	if(safe){
	    ans++;
	}
    }
    cout << ans << endl;
    return 0;
}

