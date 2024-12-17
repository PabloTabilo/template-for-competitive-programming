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
	    if(s[j] == 'X'){
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
	int k = 0;
	// Go DOWN
	int d = 0;
	while(i < n && k < 4 && puzzle[i][j] == t[k]){
	   d++;
	   k++;
	   i++;
	}
	if(d == 4) ans++;

	i = x;
	j = y;
	k = 0;
	// GO UP
	int u = 0;
	while(i >= 0 && k < 4 && puzzle[i][j] == t[k]){
	   u++;
	   k++;
	   i--;
	}
	if(u == 4) ans++;

	i = x;
	j = y;
	k = 0;
	// GO Left
	int l = 0;
	while(j >= 0 && k < 4 && puzzle[i][j] == t[k]){
	   l++;
	   k++;
	   j--;
	}
	if(l == 4) ans++;

	i = x;
	j = y;
	k = 0;
	// GO Right
	int r = 0;
	while(j < m && k < 4 && puzzle[i][j] == t[k]){
	   r++;
	   k++;
	   j++;
	}
	if(r == 4) ans++;

	i = x;
	j = y;
	k = 0;
	// GO TopLeft
	int tl = 0;
	while(i >= 0 && j >= 0 && k < 4 && puzzle[i][j] == t[k]){
	   tl++;
	   k++;
	   j--;
	   i--;
	}
	if(tl == 4) ans++;

	i = x;
	j = y;
	k = 0;
	// GO TopRight
	int tr = 0;
	while(i >= 0 && j < m && k < 4 && puzzle[i][j] == t[k]){
	   tr++;
	   k++;
	   j++;
	   i--;
	}
	if(tr == 4) ans++;

	i = x;
	j = y;
	k = 0;
	// GO BottomLeft
	int bl = 0;
	while(i < n && j >= 0 && k < 4 && puzzle[i][j] == t[k]){
	   bl++;
	   k++;
	   j--;
	   i++;
	}
	if(bl == 4) ans++;

	i = x;
	j = y;
	k = 0;
	// GO BottomRight
	int br = 0;
	while(i < n && j < m && k < 4 && puzzle[i][j] == t[k]){
	   br++;
	   k++;
	   j++;
	   i++;
	}
	if(br == 4) ans++;
    }

    cout << ans << endl;

    return 0;
}

