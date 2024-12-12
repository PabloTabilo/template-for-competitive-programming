#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

set<int> vis;
vector<int> vm;
bool foundSol = false;
int n;

void f(int mask){
    if(vm.size() == (1<<n)){
	foundSol = true;
	return;
    }

    for(int i=0;i<=16;i++){
	int val = mask ^ (1<<i);
	//cout << "mask = " << mask << ", val = " << val << endl;
	if(vis.find(val) == vis.end()){
	    //cout << "val not exists!" << endl;
	    vis.insert(val);
	    vm.push_back(val);
	    
	    f(val);
	    if(foundSol) return;

	    vis.erase(val);
	    vm.pop_back();
	}
    }
}

string bin16_str(int x){
    deque<char> dq;
    for(int i=0;i < n;i++){
	if(x & (1<<i)){
	    dq.push_front('1');
	}else{
	    dq.push_front('0');
	}
    }
    return string(dq.begin(), dq.end());
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    vm.push_back(0);
    vis.insert(0);
    f(0);
    //cout << "vm = "; 
    for(auto x: vm) cout << bin16_str(x) << endl;
    return 0;
}

