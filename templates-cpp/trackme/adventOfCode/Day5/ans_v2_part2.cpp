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

    function<bool(int, int)> isOrder = [](int first, int second){
	for(auto nn : g[first]){
	    if(nn == second) return true;
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
	    int n = pages.size();
	    
	    while(!dfs(0, pages)){
		//cout << "page: "; for(auto x : pages) cout << x << " "; cout << endl;
		stack<int> stk;
		int i = 1;
		stk.push(pages[0]);
		
		while(i < n){
		    int top = stk.top();
		    int nxt = pages[i];
		    if(!isOrder(top, nxt)){
			stk.pop();
			stk.push(nxt);
			stk.push(top);
		    }else{
			stk.push(nxt);
		    }
		    i++;
		}
		int idx = n-1;
		while(!stk.empty()){
		    int t = stk.top();
		    stk.pop();
		    pages[idx] = t;
		    idx--;
		}
		if(dfs(0, pages)){
		    //cout << "resort page: "; for(auto x : pages) cout << x << " "; cout << endl;
		    //cout << "This is corrected sorted!" << endl;
		    //cout << "mid : " << pages[n/2] << endl;
		    ans += (ll)pages[n/2];
		    //cout << "update_ans = " << ans << endl;
		}
	    }
	}
	    //cout << "-------------------" << endl;
    }
    //cout << "ans = ";
    cout << ans << endl;
    return 0;
}

