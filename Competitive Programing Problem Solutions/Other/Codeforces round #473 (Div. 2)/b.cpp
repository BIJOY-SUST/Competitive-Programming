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
map<string,ll>mp;
map<ll,ll>mp2;
vector<ll>no;
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    ll n,k,m;
    cin>>n>>k>>m;
    for(ll i=1;i<=n;i++){
        string s;
        cin>>s;
        mp[s]=i;
    }
    for(ll i=1;i<=n;i++){
        ll cost;
        cin>>cost;
        mp2[i]=cost;
    }
    for(ll i=1;i<=k;i++){
        ll d;
        cin>>d;
        while(d--){
            ll h;
            cin>>h;
            no.push_back(h);
        }
        ll mi=(1e9)+6;;
        for(ll i=0;i<no.size();i++){
            mi=min(mp2[no[i]],mi);
        }
        for(ll i=0;i<no.size();i++){
            mp2[no[i]]=mi;
        }
        no.clear();
    }
    ll ans=0;
    for(ll i=1;i<=m;i++){
        string s;
        cin>>s;
        ans+=mp2[mp[s]];
    }
    cout<<ans<<endl;
    return 0;
}
/*

*/
