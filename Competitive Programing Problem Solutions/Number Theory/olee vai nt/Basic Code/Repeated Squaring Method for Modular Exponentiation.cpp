#include<bits/stdc++.h>
using namespace std;
long long Big_Mod(long long a,long long p,long long m){
    long long ans=1%m,x=a%m;
    while(p){
        if(p&1) ans=(ans*x)%m;
        x=(x*x)%m;
        p=p>>1;
    }
    return ans;
}
int main(){
    long long a,p,m;
    while(cin>>a>>p>>m){
        cout<<Big_Mod(a,p,m)<<'\n';
    }
    return 0;
}
