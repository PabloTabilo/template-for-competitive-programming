#include <iostream>
#include <vector>
using namespace std;

class UnionFind{
private:
    int size;
    vector<int> sz;
    vector<int> ids;
    int numComponents;

public:
    UnionFind(int size);
    int find(int p);
    bool connected(int p, int q);
    int componentSize(int p);
    int getSize();
    int components();
    void unify(int p, int q);
};

UnionFind::UnionFind(int size){
    this->size = size;
    sz.resize(size,1);
    ids.resize(size,0);
    for(int i = 0; i < size; i++){
        ids[i] = i;
    }
    numComponents = size;
}

int UnionFind::find(int p){
    int root = p;
    while(root != ids[root]){
        root = ids[root];
    }

    // path compression
    while(p != root){
        int next = ids[p];
        ids[p] = root;
        p = next;
    }

    return root;
}

bool UnionFind::connected(int p, int q){
    return find(p) == find(q);
}

int UnionFind::componentSize(int p){
    return sz[find(p)];
}

int UnionFind::getSize(){
    return size;
}

int UnionFind::components(){
    return numComponents;
}

void UnionFind::unify(int p, int q){
    int root1 = find(p);
    int root2 = find(q);

    if(root1 == root2) return;

    if(sz[root1] < sz[root2]){
        sz[root2] += sz[root1];
        ids[root1] = root2;
    }else{
        sz[root1] += sz[root2];
        ids[root2] = root1;
    }
    numComponents--;
}

int main(){

    return 0;
}