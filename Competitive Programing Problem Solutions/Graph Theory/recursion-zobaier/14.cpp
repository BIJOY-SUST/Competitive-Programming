#include<bits/stdc++.h>
using namespace std;
int n,arra[100];
int bin(int i,int j,int k){
    int mid;
    if(i>j){
        return -1;
    }
    mid=(i+j)/2;
    if(arra[mid]<k) return bin(mid+1,j,k);
    if(arra[mid]>k) return bin(i,mid-1,k);
    return mid;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arra[i];
    }
    int m,k;
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>k;
        int h=bin(0,n-1,k);
        if(h==-1) cout<<"Not found"<<endl;
        else cout<<h<<endl;
    }
    return 0;
}
