
#include <iostream>
#include <map>

using namespace std;

void pA(int arr[],int n){
    cout<<endl;
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    string s = "ababd";
    int n = s.length();
    map<string, int> mymap;
    int suffix[n];

    string suff="";
    for(int i=n-1;i>=0;i--){
        suff = s[i]+suff;
        mymap[suff]=i;
    }
    int j=0;
    for(auto x : mymap) suffix[j++] = x.second;
    pA(suffix,n);    
}
