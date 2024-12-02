
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct suffix
{
    int index;
    int rank[2];
};

int cmp(struct suffix a, struct suffix b){
    return (a.rank[0]==b.rank[0]) ? (a.rank[1]<b.rank[1] ? 1:0) : (a.rank[0]<b.rank[0]?1:0);
}

int * buildSuffixArray(char * txt, int n){
    struct suffix suffixies[n];
    for(int i=0;i<n;i++){
        suffixies[i].index=i;
        suffixies[i].rank[0]=txt[i]-'a';
        suffixies[i].rank[1]=((i+1)<n) ? (txt[i+1]-'a'):-1;
    }
    // sort by rank0 and rank1
    sort(suffixies,suffixies+n,cmp);
    int ind[n];
    for(int k=4;k<2*n;k=k*2){
        int rank=0;
        int prev_rank=suffixies[0].rank[0];
        suffixies[0].rank[0]=rank;
        ind[suffixies[0].index]=0;
        for(int i=1;i<n;i++){
            // creo q esta muy demas
            if(suffixies[i].rank[0] == prev_rank && suffixies[1].rank[1] == suffixies[i-1].rank[1]){
                prev_rank=suffixies[i].rank[0];
                suffixies[i].rank[0]=rank;
            }else{
                prev_rank=suffixies[i].rank[0];
                suffixies[i].rank[0]=++rank;
            }
            ind[suffixies[i].index]=i; // quien recorri primero de lo que resort
        }
        for(int i=0;i<n;i++){
            // salto qlo q no entiendo
            int nextindex=suffixies[i].index + k/2;
            suffixies[i].rank[1]=(nextindex < n) ? suffixies[ind[nextindex]].rank[0]:-1;
        }
        // resort by rank0 and rank1
        sort(suffixies,suffixies+n,cmp);
    }
    int * suffixArr = new int[n];
    for(int i=0;i<n;i++) suffixArr[i] = suffixies[i].index;
    return suffixArr;
}

void pA(int arr[],int n){
    cout<<endl;
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    char txt[] = "ababd";
    int n = strlen(txt);
    int * suffixArr = buildSuffixArray(txt,n);
    pA(suffixArr,n);
}


