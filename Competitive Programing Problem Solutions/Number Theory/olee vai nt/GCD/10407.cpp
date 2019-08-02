#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        if(n==0) break;
        int ans=0;
        int m;
        while(cin>>m){
            if(m==0) break;
            ans=__gcd(ans,abs(m-n));
        }
        cout<<ans<<'\n';
    }
    return 0;
}
