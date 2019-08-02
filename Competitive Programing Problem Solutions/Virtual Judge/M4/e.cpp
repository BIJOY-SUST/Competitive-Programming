#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
// getit() : replaces 1 with 9 in binary conversion !
ll getit(ll n){
    ll ret=0;
    vector<ll> v;
    while(n){
        ll k=0;
        if(n%2!=0)
            k=9;
        v.push_back(k);
        n/=2;
    }
    for(int i=v.size()-1;i>=0;i--){
        ret = 10*ret+v[i];
    }
    return ret;
}
bool fun(ll a,ll b){
    b=getit(b);
    if(b%a)
        return 0;
    //cout<<b<<endl;
    return 1;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        for(int i=1;;i++){
            if(fun(n,i)){
                //cout<<i<<endl;
                cout<<getit(i)<<endl;
                break;
            }
        }
    }
    return 0;
}
