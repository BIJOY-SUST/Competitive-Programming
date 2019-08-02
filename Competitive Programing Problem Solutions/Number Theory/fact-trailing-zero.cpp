#include<bits/stdc++.h>
using namespace std;
int trailing(long long int n){
    long long int i=5,c=0;
    ///for(long long int i=5;n>=i;i*=5){
    while(i<=n){
        c+=n/i;
        i*=5;
    }
    return c;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n;
    cin>>n;
    cout<<trailing(n)<<"\n";
    return 0;
}
