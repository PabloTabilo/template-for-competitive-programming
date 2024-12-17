#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<string> puzzle;
int n;
int m;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s;
    vector<pair<int, int>> start;
    while(getline(cin, s)){
	if(s.empty()) break;
	puzzle.push_back(s);
	m = s.length();
	for(int j=0;j<m;j++){
	    if(s[j] == 'A'){
		start.push_back({puzzle.size()-1,j});
	    }
	}
    }
    string t = "XMAS";
    n = puzzle.size();
    int ans = 0;
    for(auto [x, y] : start){
	int i = x;
	int j = y;
	char tl = 'X';
	if(i-1 >= 0 && j-1 >= 0){
	    tl = puzzle[i-1][j-1];
	}else continue;

	char br = 'X';
	if(i+1 < n && j+1 < m){
	    br = puzzle[i+1][j+1];
	}else continue;
	if(tl == 'X' || br == 'X' || tl == 'A' || br == 'A' || tl == br) continue;
	
	char tr = 'X';
	if(i-1 >= 0 && j+1 < m){
	    tr = puzzle[i-1][j+1];
	}else continue;

	char bl = 'X';
	if(i+1 < n && j-1 >= 0){
	    bl = puzzle[i+1][j-1];
	}else continue;
	if(tr == 'X' || bl == 'X' || tr == 'A' || bl == 'A' || tr == bl) continue;
	ans++;
    }

    cout << ans << endl;

    return 0;
}

