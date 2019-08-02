#include<bits/stdc++.h>
#define mx 100010
using namespace std;
#define ll long long
ll sum[mx];
ll a[mx],n;
bool check(ll d){
    ll s=0;
    int c=0;
    for(ll i=1;i<=n;i++){
        s+=a[i];
        if(s==d){
            s=0;
            c++;
        }
        else if(s>d){
            return 0;
        }
    }
    if(s==0 and c>=2) return 1;
    return 0;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ll n;
    cin>>n;
    string s;
    cin>>s;
    for(ll i=1;i<=n;i++){
//        cin>>a[i];
            a[i]=s[i-1]-'0';
        sum[i]=sum[i-1]+a[i];
    }
//    for(ll i=1;i<=n;i++){
//        cout<<sum[i]<<nl;
//    }
//    ll d=a[1];
    if(sum[n]==0) return cout<<"YES"<<endl,0;

    for(ll i=1;i<=sum[n];i++){
        bool f=check(i);
        if(f){
            return cout<<"YES"<<endl,0;
        }
//        else cout<<"NO"<<nl;
    }
    cout<<"NO"<<endl;
    return 0;
}
