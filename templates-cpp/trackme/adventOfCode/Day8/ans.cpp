#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int n;
int m;
vector<string> grid;
unordered_map<char, vector<pair<int,int>> > antenna;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    {
	string line;
	while(true){
	    if(!getline(cin, line)) break;
	    grid.push_back(line);
	    m = line.length();	    
	    for(int x=0;x<m;x++){
		if(line[x] != '.'){
		    int y = grid.size()-1; 
		    antenna[line[x]].push_back({y, x});
		}
	    }
	}
    }
    n = grid.size();

    //cout << "original grid: "<<endl; for(auto y : grid){for(auto x : y) cout << x << " ";cout <<endl;}cout <<endl;
    
    int cnt = 0;
    set<pair<int, int>> vis;
    for(auto [k, v] : antenna){
	int sz = v.size();
	//cout << "k = " << k << endl;
	for(int i=0;i<sz;i++){
	    auto [y1, x1] = v[i];
	    for(int j=i+1;j<sz;j++){
		auto [y2, x2] = v[j];
		//cout << "y1, x1 = " << y1 << ", " << x1 << endl;
		//cout << "y2, x2 = " << y2 << ", " << x2 << endl;

		int dy = y1 - y2;
		int dx = x1 - x2;
		
		//cout << "dx = " << dx << ", dy = " << dy << endl;

		int anti1Y = y1 + dy;
		int anti1X = x1 + dx;
		
		int anti2Y = y2 - dy;
		int anti2X = x2 - dx;
		
		//cout << "anti1Y, anti1X = " << anti1Y << ", " << anti1X << endl;
		//cout << "anti2Y, anti2X = " << anti2Y << ", " << anti2X << endl;

		if(anti1X >= 0 && anti1X < m && anti1Y >= 0 && anti1Y < n){
		    if(vis.find({anti1Y, anti1X}) == vis.end()){
			vis.insert({anti1Y, anti1X});
			cnt++;
			if(grid[anti1Y][anti1X] == '.'){
			    grid[anti1Y][anti1X] = '#';
			}
		    }
		}
		
		if(anti2X >= 0 && anti2X < m && anti2Y >= 0 && anti2Y < n){
		    if(vis.find({anti2Y, anti2X}) == vis.end()){
			vis.insert({anti2Y, anti2X});
			cnt++;
			if(grid[anti2Y][anti2X] == '.'){
			    grid[anti2Y][anti2X] = '#';
			}
		    
		    }
		}
		
		//cout << "Upgrade grid: "<<endl; for(auto y : grid){for(auto x : y) cout << x << " ";cout <<endl;}cout <<endl;
		//cout << "cnt = " << cnt << endl;
		//cout << "============" << endl;
	    }
	    //cout << "-----------------" << endl;
	}
	//cout << "**************" << endl;
    }
    //cout << "Upgrade grid: "<<endl; for(auto y : grid){for(auto x : y) cout << x << " ";cout <<endl;}cout <<endl;
    //cout << "cnt = ";
    cout << cnt << endl;

    return 0;
}

