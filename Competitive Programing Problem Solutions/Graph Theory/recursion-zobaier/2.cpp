#include<bits/stdc++.h>
using namespace std;
int n,arra[100];
void print(int u,int v,int *arra){
    if(u<=v){
        cout<<arra[u]<<" "<<arra[v]<<endl;
        print(u+1,v-1,arra);
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arra[i];
    }
    print(0,n-1,arra);
    return 0;
}

