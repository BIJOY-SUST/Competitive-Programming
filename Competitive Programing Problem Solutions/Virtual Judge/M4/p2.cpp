#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int c = 0;
    for(int i=0;i<(n*n)/2;i++){
        c+=2;
        cout<<i+1<<" ";
        cout<<n*n-i<<" ";
        if(c==n){
            cout<<endl;
            c = 0;
        }
    }
    return 0;
}
