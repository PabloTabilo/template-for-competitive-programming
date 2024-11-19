#include<iostream>

using namespace std;

int checkOdd(int A[], int n){
    int res=0;
    for(int i=0;i<n;i++){
        res^=A[i];
    }
    return res;
}

bool fastOdd(int x){
    if(x&1)
        return true;
    return false;
}

int main(){
    int A[7]={12,12,14,90,14,14,14};
    int n=7;
    int res;
    res = checkOdd(A,n);
    cout<<res<<endl;
    int x=10;
    cout<<fastOdd(x)<<endl;
    int z=15;
    cout<<fastOdd(z)<<endl;
    int a=5;
    cout<<"-a: "<<~a<<endl;
    int b = ~a;
    cout<<"a&-a: "<<a & b;
    return 0;
}
