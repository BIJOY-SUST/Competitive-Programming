#include<bits/stdc++.h>
using namespace std;
long long Big_Mod(long long a,long long p,long long m){
    if(p==0){
        return 1%m;
    }
    if(p%2){
        long long x = Big_Mod(a,p-1,m)%m;
        return ((a%m)*(x%m))%m;
    }
    else{
        long long x = Big_Mod(a,p/2,m)%m;
        return ((x%m)*(x%m))%m;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long a,p,m;
    while(cin>>a>>p>>m){
        cout<<Big_Mod(a,p,m)<<"\n";
    }
    return 0;
}
