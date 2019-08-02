#include<bits/stdc++.h>
using namespace std;
int n,arra[100];
void print(int k){
    if(k<n&&arra[k]%2==0){
        cout<<arra[k]<<" ";
        print(k+1);
    }
    else if(k<n&&arra[k]%2==1){
        print(k+1);
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arra[i];
    }
    print(0);
    return 0;
}
