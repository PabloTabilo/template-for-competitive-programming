#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<string> grid;

int n;
int m;
int sx;
int sy;

int cnt = 0;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int x = -1;
    int y = -1;
    // idea:
    // build rectangles
    // need 3 vertex for the 4th vertex position
    {
	string line;
	while(true){
	    if(!getline(cin, line)) break; // EOF or error
	    grid.push_back(line);
	    if(x == -1){
		m = line.length();
		for(int j = 0; j < m; j++){
		    if(line[j] == '^'){
			sx = grid.size() - 1;    
			sy = j;
		    }
		}
	    }
	}
    }
    n = grid.size();
    
    //cout << "original puzzle:"<<endl;for(string s : grid){for(char c : s) cout << c << " ";cout << endl;}cout << endl;

    for(int i=0; i<n;i++){
	for(int j=0;j<m;j++){
	    if(grid[i][j] == '.'){
		grid[i][j] = '#';
		int x = sx;
		int y = sy;
		bool cycle = false;
		bool out_grid = false;
		vector<string> ngrid = grid;
		vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(m, vector<bool>(4, false)));
		pair<int, int> orientation = {-1,0};
		////cout << "start puzzle:"<<endl;for(string s : ngrid){for(char c : s) cout << c << " ";cout << endl;}cout << endl;
		while(true){
		    if(!cycle && orientation.first == -1){
			int i = x;
			for(;i>=0;i--){
			    if(ngrid[i][y] == '#'){
				orientation.first = 0;
				orientation.second = 1;
				break;
			    }
			    if(vis[i][y][0]){
				cnt++;
				cycle = true;
				//cout << "cycle repeat ^ for this: i, y = " << i << "," << y << endl;
				break;
			    }
			    vis[i][y][0] = true;
			    ngrid[i][y] = 'x';
			}
			if(i == -1){
			    out_grid = true;
			    break;
			}
			x = i+1;
		    }
		    if(out_grid || cycle) break;

		    if(!cycle && orientation.first == 1){
			int i = x;
			for(;i<n;i++){
			    if(ngrid[i][y] == '#'){
				orientation.first = 0;
				orientation.second = -1;
				break;
			    }
			    
			    if(vis[i][y][1]){
				cnt++;
				cycle = true;
				//cout << "cycle repeat v for this: i, y = " << i << "," << y << endl;
				break;
			    }
			    vis[i][y][1] = true;
			    ngrid[i][y] = 'x';
			}
			if(i == n){
			    out_grid = true;
			    break;
			}
			x = i-1;
		    }
		    if(out_grid || cycle) break;

		    if(!cycle && orientation.second == 1){
			int j = y;
			for(;j<m;j++){
			    if(ngrid[x][j] == '#'){
				orientation.first = 1;
				orientation.second = 0;
				break;
			    }
			    if(vis[x][j][2]){
				cnt++;
				cycle = true;
				//cout << "cycle repeat > for this: x, j = " << x << "," << j << endl;
				break;
			    }
			    vis[x][j][2] = true;
			    ngrid[x][j] = 'x';
			}
			if(j == m){
			    out_grid = true;
			    break;
			}
			y = j-1;
		    }
		    if(out_grid || cycle) break;

		    if(!cycle && orientation.second == -1){
			int j = y;
			for(;j>=0;j--){
			    if(ngrid[x][j] == '#'){
				orientation.first = -1;
				orientation.second = 0;
				break;
			    }
			    if(vis[x][j][3]){
				cnt++;
				cycle = true;
				//cout << "cycle repeat < for this: x, j = " << x << "," << j << endl;
				break;
			    }
			    vis[x][j][3] = true;
			    ngrid[x][j] = 'x';
			}
			if(j == -1){
			    out_grid = true;
			    break;
			}
			y = j+1;
		    }
		    if(out_grid || cycle) break;
		}
		//if(cycle){
		    //cout << "cycle ? puzzle:"<<endl;for(string s : ngrid){for(char c : s) cout << c << " ";cout << endl;}cout << endl;
		//}
		grid[i][j] = '.';
	    }
	}
    }
    //cout << "cnt = ";
    cout << cnt << endl;

    return 0;
}

