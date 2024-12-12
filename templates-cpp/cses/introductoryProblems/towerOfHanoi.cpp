#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int n;
set<string> mySet;
void f(int i, string s){
    if(mySet.find(s) != mySet.end()){
	return;
    }
    mySet.insert(s);
    for(int j=0;i<n;i++){
	if(i == j) continue;
	if(s[i] == s[j]) continue;
	swap(s[i], s[j]);
	f(j, s);
	swap(s[i], s[j]);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    n = s.length();
    f(0,s);
    cout << mySet.size() << endl;
    for(auto x : mySet){
	cout << x << endl;
    }
    return 0;
}

