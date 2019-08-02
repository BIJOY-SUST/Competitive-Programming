#include<bits/stdc++.h>
using namespace std;
int n,arra[100];
void print(int k){
    if(n%2==0&&k<(n/2)){
        print(k+1);
        cout<<arra[k]<<" "<<arra[n-1-k]<<endl;
    }
    if(n%2!=0&&k<=(n/2)){
        print(k+1);
        cout<<arra[k]<<" "<<arra[n-1-k]<<endl;
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arra[i];
    }
    int k=0;
    print(k);
    return 0;
}
