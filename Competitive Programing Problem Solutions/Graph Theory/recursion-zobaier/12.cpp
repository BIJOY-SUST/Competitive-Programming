#include<bits/stdc++.h>
using namespace std;
int n,arra[100],fm,sm,h=0;
void print(int k){

    if(sm<arra[k]){
        sm=arra[k];
        if(sm>fm){
            sm=fm;
            fm=arra[k];
        }

    }
    if(k<n){
        return print(k+1);
    }
    else if(k>=n){
        cout<<sm<<endl;
        return;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arra[i];
    }
    fm=sm=arra[0];
    print(0);
    }
    return 0;
}
