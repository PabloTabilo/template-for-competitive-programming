#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string line;
    char c;
    while(scanf("%c", &c) != EOF){
	line += c;
    }
    line += "########";
    ll ans = 0;
    int cnt = 0;
    //cout << "line : " << line << endl;
    int n = line.length();
    bool do_action = true;
    for(int i=0;i<n;i++){
	if(line[i] == 'd'){
	    if(i+1 < n && line[i+1] == 'o'){
		string word = "";
		string isDo = "do()";
		string isDont = "don't()";
		int r = i;
		while(word.size() != isDont.size()){
		    if(word == isDo) break;
		    word += line[r];
		    r++;
		}
		if(word == isDo){
		    do_action = true;
		}
		if(word == isDont){
		    do_action = false;
		}
		cout << "word = " << word << endl;
	    }
	}
	if(line[i] == 'm'){
	    int r = i;
	    bool impossible = false;
	    string prefix="mul(";
	    string temp = "";
	    while(r < n && temp.size() != prefix.size()){
		temp.push_back(line[r]);
		r++;
	    }
	    if(prefix != temp){
		continue;
	    }
	    cnt++;
	    //cout << "temp = " << temp << endl;
	    ll d1 = -1;
	    while(r < n && line[r] != ','){
		ll num = line[r]-'0';
		temp.push_back(line[r]);
		if(num > 9 || num < 0){
		    impossible = true;
		    break;
		}
		if(d1 == -1) d1 = 0;
		d1 = d1*10 + num;
		r++;
	    }
	    temp.push_back(',');
	    //cout << "temp = " << temp << ", d1 = " << d1 << endl;
	    if(d1 == -1){
		continue;
	    }
	    if(impossible){
		continue;
	    }
	    r++; // next digit, here iam comma
	    ll d2 = -1;
	    while(r < n && line[r] != ')'){
		ll num = line[r]-'0';
		temp.push_back(line[i]);
		if(num > 9 || num < 0){
		    impossible = true;
		    break;
		}
		if(d2 == -1) d2 = 0;
		d2 = d2*10 + num;
		r++;
	    }
	    temp.push_back(')');
	    //cout << "temp = " << temp << ", d2 = " << d2 << endl;
	    if(impossible){
		continue;
	    }
	    if(d1 == -1 || d2 == -1){
		// not enter
		continue;
	    }
	    ll mult = d1 * d2;
	    if(do_action){
		ans += mult;
	    }
	    cout << "CORRECT >> temp = " << temp << ", mult = " << mult << ", ans = " << ans << endl;
	}
    }
    cout << "cnt = " << cnt << endl;
    cout << ans << endl;
    return 0;
}

