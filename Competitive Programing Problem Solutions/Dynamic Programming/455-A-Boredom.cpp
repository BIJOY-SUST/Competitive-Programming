#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define mx             100010
#define inf            0x3f3f3f3f
#define mod            1000000007
#define PI             2*acos(0.0)
#define E              2.71828182845904523536
#define ll             long long int
#define ull            unsigned long long int
#define pii            pair<int,int>
#define pll            pair<ll,ll>
#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
#define fast           ios_base::sync_with_stdio(false),cin.tie(NULL)
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
template <typename T> bool bitcheck(T p,T pos){return (bool)(p&(1<<pos));}
template <typename T> T biton(T p,T pos){return p=p|(1<<pos);}
template <typename T> T bitoff(T p,T pos){return p=p&~(1<<pos);}
template <typename T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
template <typename T> T POW(T b,T p) {T Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
template <typename T> T BigMod(T b,T p,T Mod) {T Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
template <typename T> T ModInverse(T p,T Mod) {return BigMod(p,Mod-2,Mod);}
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//********************************************Code Start Here*********************************************************//
map<ll,ll>mp;
vector<pair<ll,ll> >dp(mx);
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    ll n;
    cin>>n;
    for(int i=0;i<n;i++){
        ll h;
        cin>>h;
        if(mp[h]==0){
            mp[h]=1;
        }
        else mp[h]++;
    }
    int cnt=0;
    dp[cnt].first=0;
    dp[cnt].second=0;
    for(auto x:mp){
//        cout<<x.first<<" "<<x.second<<endl;
        ++cnt;
        dp[cnt].first=x.first;
        dp[cnt].second=x.first*x.second;
    }
//    cout<<mp.size()<<endl;
//    cout<<cnt<<endl;
//    for(int i=0;i<=cnt;i++){
//        cout<<dp[i].first<<" "<<dp[i].second<<endl;
//    }
    for(int i=2;i<=cnt;i++){
        bool f=false;
        if(dp[i].first==dp[i-1].first+1){
            f=true;
        }
        if(f){
            dp[i].second+=dp[i-2].second;
        }
        else{
            dp[i].second+=dp[i-1].second;
        }
        dp[i].second=max(dp[i].second,dp[i-1].second);
//        cout<<dp[i].second<<endl;
    }
    cout<<dp[cnt].second<<'\n';
    return 0;
}
/*

*/

