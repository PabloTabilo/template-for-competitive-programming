#include <bits/stdc++.h>
using namespace std;

using ll = long long;

unordered_map<int, vector<int>> g;

vector<int> bfs(int s, unordered_map<int, int> ind){
    queue<int> q;
    q.push(s);
    // order + same tree or component
    vector<int> orderPath;
    while(!q.empty()){
	int top = q.front();
	q.pop();
	orderPath.push_back(top);
	for(int neigh : g[top]){
	    ind[neigh]--;
	    if(ind[neigh] == 0){
		q.push(neigh);
	    }
	}
    }
    return orderPath;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    vector<string> lines;
    {
	string line;
	while(true){
	    if(!getline(cin, line)) break; // EOF or error
	    lines.push_back(line);
	    //cout << "line = " << line << endl;
	}
    }

    unordered_map<int, int> indegree;
    size_t idx = 0;
    for(;idx<lines.size();++idx){
	string & line = lines[idx];
	if(line.empty()){
	    break;
	}
	if(line.find('|') == string::npos){
	    break;
	}
	int u, v;
	char trash;
	stringstream ss(line);
	if(ss >> u >> trash >> v){
	    cout << "u -> v = " << u << " -> " << v << endl;
	    g[u].push_back(v);
	    indegree[v]++;
	    if(indegree.count(u) == 0){
		indegree[u] = 0;
	    }
	}
    }
    //cin.ignore();
    // clear the EOF state
    //cin.clear();
    // clear the input buffer
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.ignore();
    vector<vector<int>> paths;
    for(auto [k, v] : indegree){
	if(v == 0){
	    // get the path
	    vector<int> orderPath = bfs(k, indegree);
	    paths.push_back(orderPath);
	}
    }

    for(auto v : paths){cout << "path: "; for(auto x : v) cout << x << " " ; cout << endl;}

    ll ans = 0;
    for(;idx < lines.size();++idx){
	string & line = lines[idx];
	if(line.empty()) continue;
	if(line.find(',') != string::npos){
	    vector<int> pages;
	    {
		stringstream ss(line);
		string temp;
		while(getline(ss, temp, ',')){
		    pages.push_back(stoi(temp));
		}
	    }
	    //cout << "page: "; for(auto x : pages) cout << x << " "; cout << endl;
	    int n = pages.size();
	    for(auto path : paths){
		int sz = path.size(); 
		int p1 = 0;
		int p2 = 0;
		while(p1 < sz && p2 < n){
		    while(p1 < sz && p2 < n && path[p1] == pages[p2]){
			p1++;
			p2++;
		    }
		    while(p1 < sz && path[p1] != pages[p2]) p1++;
		}
		//cout << "p1 = " << p1 << ", p2 = " << p2 << endl;
		if(p2 >= n){
		    //cout << "This is corrected sorted!" << endl;
		    //cout << "mid : " << pages[n/2] << endl;
		    ans += (ll)pages[n/2];
		    //cout << "update_ans = " << ans << endl;
		    break;
		}
	    }
	    //cout << "-------------------" << endl;
	}
    }
    //cout << "ans = ";
    cout << ans << endl;
    return 0;
}

