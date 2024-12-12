#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

vector<string> board;
set<int> occupiedCols;
set<pair<int, int>> queens;

int ans = 0;

bool diag(int x, int y){
    for(int i=x-1;i>=0;i--){
	int j1 = y - (x - i);
	int j2 = y + (x - i);
	if(queens.find({i, j1}) != queens.end()){
	    return true;
	}
	if(queens.find({i, j2}) != queens.end()){
	    return true;
	}
    }
    return false;
}

void f(int i){
    if(i >= 8){
	ans++;
	return;
    }
    for(int j=0;j<8;j++){
	if(occupiedCols.find(j) != occupiedCols.end()) continue;
	if(diag(i, j)) continue;
	if(board[i][j] == '.'){
	    board[i][j] = 'Q';
	    occupiedCols.insert(j);
	    queens.insert({i, j});
	    f(i+1);
	    queens.erase({i, j});
	    occupiedCols.erase(j);
	    board[i][j] = '.';
	}

    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    board.resize(8);
    for(int i=0;i<8;i++){
	cin >> board[i];
    }

    for(int j=0;j<8;j++){
	if(board[0][j] == '.'){
	    board[0][j] = 'Q';
	    occupiedCols.insert(j);
	    queens.insert({0, j});
	    f(1);
	    queens.erase({0, j});
	    occupiedCols.erase(j);
	    board[0][j] = '.';
	}
    }

    cout << ans << endl;

    return 0;
}

