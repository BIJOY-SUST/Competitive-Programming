//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

//#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
//#include <ext/pb_ds/detail/standard_policies.hpp>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
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
#define one(x)         __builtin_popcount(x)
#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
#define unique(x)      x.erase(unique(x.begin(),x.end()),x.end())
#define fast           ios_base::sync_with_stdio(false),cin.tie(NULL)
#define forstl(x)      for(__typeof(x.begin()) it=(x.begin());it!=(x.end());++it)
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
template <typename T> bool bitcheck(T p,T pos){return (bool)(p&(1<<pos));}
template <typename T> T biton(T p,T pos){return p=p|(1<<pos);}
template <typename T> T bitoff(T p,T pos){return p=p&~(1<<pos);}
template <typename T> ll toint(T s) {ll p;stringstream ss(s); ss>>p; return p;}
template <typename T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
template <typename T> T POW(T b,T p) {T Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
template <typename T> T BigMod(T b,T p,T Mod) {T Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
template <typename T> T ModInverse(T p,T Mod) {return BigMod(p,Mod-2,Mod);}
//template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//template <typename T> using ordered_set2 = tree<pair <T, string>, null_type, less<pair <T, string>>, rb_tree_tag, tree_order_statistics_node_update>;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ll arr[mx];
ll boss(ll l,ll r,ll h){
    if(r<=l) return 0;
    ll pos=min_element(arr+l,arr+r)-arr;
    ll ans=min(r-l,boss(l,pos,arr[pos])+boss(pos+1,r,arr[pos])+arr[pos]-h);
    return ans;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    ll n; cin>>n;
    for(ll i=0;i<n;i++)cin>>arr[i];
    ll ans=boss(0,n,0);
    cout<<ans<<'\n';
    return 0;
}