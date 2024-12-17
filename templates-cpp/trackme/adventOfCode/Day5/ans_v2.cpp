#include <bits/stdc++.h>
using namespace std;

using ll = long long;

unordered_map<int, vector<int>> g;

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
	    g[u].push_back(v);
	}
    }
    
    function<bool(int, vector<int> &)> dfs = [&](int i, vector<int> &ord){
	if(i >= ord.size() - 1){
	    return true;
	}
	for(auto neigh : g[ord[i]]){
	    if(ord[i+1] == neigh){
		return dfs(i+1, ord);
	    }
	}
	return false;
    };

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
	    if(dfs(0, pages)){
		//cout << "This is corrected sorted!" << endl;
		//cout << "mid : " << pages[n/2] << endl;
		ans += (ll)pages[n/2];
		//cout << "update_ans = " << ans << endl;
	    }
	}
	    //cout << "-------------------" << endl;
    }
    //cout << "ans = ";
    cout << ans << endl;
    return 0;
}

