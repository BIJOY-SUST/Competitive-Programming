#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll func(ll x){
    ll ans=0;
    vector<ll>v;
    while(x){
        ll h=0;
        if(x%2){
            h=9;
        }
        v.push_back(h);
        x=x/2;
    }
    for(ll i = v.size()-1;i>=0;i--){
        ans = 10*ans+v[i];
    }
    return ans;
}
ll tests(ll N,ll x){
    x = func(x);
    if(x%N){
        return 0;
    }
    else{
        return 1;
    }
}
int main(){
    ll T,N;
    cin>>T;
    while(T--){
        cin>>N;
        for(ll x=1;;x++){
            if(tests(N,x)){
                cout<<func(x)<<endl;
                break;
            }
        }
    }
    return 0;
}
