#include<bits/stdc++.h>
using namespace std;

vector<int> z_function(string & s){
    int n = s.size();
    vector<int> z(n,0);
    int l = 0, r = 0;
    for(int i=1;i<n;i++){
	
	if(i < r){
	    z[i] = min(r - i, z[i - l]);
	}

	while(i + z[i] < n && s[z[i]] == s[i + z[i]]){
	    z[i]++;
	}

	if(i + z[i] > r){
	    l = i;
	    r = i + z[i];
	}

    }
    return z;
}

// Function to solve the problem using Z-algorithm
int minOperationsToSubstringZ(int n, int m, string x, string s) {
    string currentX = x;
    int operations = 0;
    while (currentX.size() < s.size() + x.size()) {
        string combined = s + "$" + currentX;
        vector<int> z = z_function(combined);
        // Check if the pattern appears in the text
        for (int i = s.size() + 1; i < combined.size(); ++i) {
            if (z[i] >= s.size()) {
                return operations;
            }
        }
        currentX += currentX; // Double the string
        operations++;
    }
    // Final check after exiting the loop
    string combined = s + "$" + currentX;
    vector<int> z = computeZ(combined);
    for (int i = s.size() + 1; i < combined.size(); ++i) {
        if (z[i] >= s.size()) {
            return operations;
        }
    }
    return -1; // Impossible
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        string x, s;
        cin >> n >> m >> x >> s;
        cout << minOperationsToSubstringZ(n, m, x, s) << endl;
    }
    return 0;
}

