#include<iostream>

using namespace std;

class SegmentTree{
public:
    int n;
    vector<int> tree;
    SegmentTree(int n) : n(n), tree(2*n, 0){}
    // 1 based index
    void build(const vector<int> & data){
        for(int i=0;i<n;i++){
            tree[n + i] = data[i];
        }
        for(int i=n-1;i>0;i--){
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
    }

    // update operation

    // query from root
    // high of the tree, if the vector is power of 2 of size n, so O(log n)
    int query(int node, int node_low, int node_high, int query_low, int query_high){
        if(query_low <= node_low && node_high <= query_high){
            return tree[node];
        }
        if(query_high < node_low || query_low > node_high){
            return 0;
        }
        int mid = (node_low + node_high) >> 1;
        return query(2*node,node_low,mid,query_low,query_high) + query(2*node+1, mid + 1, node_high,query_low,query_high);
    }
    // query from leaf nodes
};


int main(){
    // type prefix sum
    vector<int> v = {6,10,5,2,7,8,0,9};
    int power2 = 1;
    while(v.size() < power2) power2 <<= 1;
    while(v.size() > power2) v.push_back(0);
    int l = 1;
    int r = 5;
    cout << st.query(1,0,st.n-1,l,r) << endl;
    return 0;
}