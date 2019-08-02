#include<bits/stdc++.h>
using namespace std;
int n,arra[100],d;
void print(int k){

    if(d<arra[k]){
        d=arra[k];
    }
    if(k<n){
        print(k+1);
    }
    else if(k>=n){
        cout<<d<<endl;
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arra[i];
    }
    d=arra[0];
    print(0);
    return 0;
}

