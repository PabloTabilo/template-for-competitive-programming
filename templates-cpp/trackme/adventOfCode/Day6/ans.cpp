#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<string> lines;
int n;
int m;
int pos = 0;

bool dfs(int x, int y, int orX, int orY){
    if(orX != 0){
	if(orX == -1){
	    int i=x;
	    for(;i>=0;i--){
		if(lines[i][y] == '#'){
		    break;
		}
		if(lines[i][y] == '.') pos++;
		lines[i][y] = 'X';
	    }
	    if(i == -1){
		// limit, not advance
		return true;
	    }else{
		// found a block, change orientation
		return dfs(i+1, y, 0, 1);
	    }
	}
	if(orX == 1){
	    int i=x;
	    for(;i<n;i++){
		if(lines[i][y] == '#'){
		    break;
		}
		if(lines[i][y] == '.') pos++;
		lines[i][y] = 'X';
	    }
	    if(i == n){
		// limit, not advance
		return true;
	    }else{
		// found a block, change orientation
		return dfs(i-1, y, 0, -1);
	    }
	}
    }
    else if(orY != 0){
	if(orY == -1){
	    int j=y;
	    for(;j>=0;j--){
		if(lines[x][j] == '#'){
		    break;
		}
		if(lines[x][j] == '.') pos++;
		lines[x][j] = 'X';
	    }
	    if(j == -1){
		// limit, not advance
		return true;
	    }else{
		// found a block, change orientation
		return dfs(x, j+1, -1, 0);
	    }
	}
	if(orY == 1){
	    int j=y;
	    for(;j<m;j++){
		if(lines[x][j] == '#'){
		    break;
		}
		if(lines[x][j] == '.') pos++;
		lines[x][j] = 'X';
	    }
	    if(j == m){
		// limit, not advance
		return true;
	    }else{
		// found a block, change orientation
		return dfs(x, j-1, 1, 0);
	    }
	}
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int x = -1;
    int y = -1;
    {
	string line;
	while(true){
	    if(!getline(cin, line)) break; // EOF or error
	    lines.push_back(line);
	    if(x == -1){
		m = line.length();
		for(int j = 0; j < m; j++){
		    if(line[j] == '^'){
			x = lines.size() - 1;    
			y = j;
		    }
		}
	    }
	}
    }
    n = lines.size();
    //cout << "original puzzle:"<<endl;for(string s : lines){for(char c : s) cout << c << " ";cout << endl;}cout << endl;
    lines[x][y] = '.'; 
    dfs(x, y, -1, 0);
    
    //cout << "post dfs puzzle:"<<endl;for(string s : lines){for(char c : s) cout << c << " ";cout << endl;}cout << endl;
    
    //cout << "pos = ";
    cout << pos << endl;

    return 0;
}

