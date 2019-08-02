#include<bits/stdc++.h>
using namespace std;
int n,arra[100],d=0;
void print(int k,int j){

    if(j==arra[k]){
        cout<<k<<endl;
        return;
    }
    if(k>=n){
        cout<<"not found"<<endl;
        return;
    }
    return print(k+1,j);
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arra[i];
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int j;
        cin>>j;
        print(0,j);
    }
    return 0;
}
