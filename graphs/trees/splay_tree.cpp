#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<iterator>
#include<stack>
#include<set>
#include<unordered_map>
#include<map>
#include<math.h>
#include<limits>
#include<iomanip>
#include<sstream>
#include<tuple>
#include<chrono>
#include<cstring>

using namespace std;
using namespace chrono;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define _USE_MATH_DEFINES
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second

typedef long int int32;
typedef unsigned long int uint32;
typedef long long ll;
typedef unsigned long long int ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}

class Node{
    public: 
        int id;
        int data;
        Node * left=nullptr;
        Node * right=nullptr;
        Node(int id, int data){
            this->id=id;
            this->data=data;
        }
};

class BST{
    private:
        int id=0;
    public:
        Node * root=nullptr;
        BST(int root_data);
        Node * insert(Node * root,int value);
        void levelorder();
};


BST::BST(int root_data){
    root = new Node(++id,root_data);
}

Node * BST::insert(Node * curr, int value){
    if(curr==nullptr) return new Node(++id,value);
    if(value > curr->data){
        curr->right = insert(curr->right, value);
    }else if(value < curr->data){
        curr->left = insert(curr->left, value);
    }
    if(curr!=root) curr->id=++id;
    return curr;
}

void BST::levelorder(){
    Node * curr = root;
    queue<Node *> q1;
    q1.push(curr);
    map<int,bool> visited;
    int id,data;
    while(!q1.empty()){
        curr = q1.front();
        q1.pop();
        id = curr->id;
        data = curr->data;
        cout<<"id,value="<<id<<","<<data<<endl;
        if(visited.find(id)!=visited.end()) continue;
        visited[curr->id]=true;
        if(curr->left!=nullptr) q1.push(curr->left);
        if(curr->right!=nullptr) q1.push(curr->right);
    }
}



void solve(){
    BST t(12);
    t.insert(t.root,10);
    t.insert(t.root,17);
    t.insert(t.root,20);
    t.insert(t.root,5);
    t.insert(t.root,8);
    t.levelorder();
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    auto start1 = high_resolution_clock::now();
    // read & write file
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef ONLINE_JUDGE
	cerr << "Time: " << duration . count() / 1000 << endl;
#endif
    return 0;
}

