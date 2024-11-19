#include<iostream>

using namespace std;

void printArr(int A[], int n){
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;
}

void mergeSort(int A[], int l, int m, int r){
    int n1=m-l+1;
    int n2=r-m;
    int L[n1];
    int R[n2];
    for(int i=0;i<n1;i++)
        L[i]=A[l+i];
    for(int i=0;i<n2;i++)
        R[i]=A[m+i+1];
    int i=0;
    int j=0;
    int k=l;
    while(i<n1&&j<n2){
        if(L[i]<R[j])
            A[k++]=L[i++];
        else
            A[k++]=R[j++];
    }
    for(;i<n1;i++)
        A[k++]=L[i];
    for(;j<n2;j++)
        A[k++]=R[j];
}

void merge(int A[], int l, int r){
    if(l<r){
        int m=(l+r)/2;
        merge(A, l, m);
        merge(A,m+1,r);
        mergeSort(A,l,m,r);
    }
}
int main(){
    int A[6]={1,5,7,4,4,3};
    int n=6;
    printArr(A,n);
    merge(A,0,n-1);
    printArr(A,n);
}
