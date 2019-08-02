#include<bits/stdc++.h>
using namespace std;
int n,ara[100];
void print(int k){
    if(k<n){
        print(k+1);
        cout<<ara[k]<<endl;
    }
}
int main(){

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ara[i];
    }
    int k=0;
    print(k);
    return 0;
}
