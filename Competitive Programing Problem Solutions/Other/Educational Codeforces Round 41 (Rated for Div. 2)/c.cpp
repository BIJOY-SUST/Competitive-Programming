#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define mx             110
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
ll dp[5][110][110],boss[220][220],temp[220][220];
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    ll n;
    cin>>n;
    for(ll k=1;k<=4;k++){
        for(ll i=1;i<=n;i++){
            string s;
            cin>>s;
            for(ll j=1;j<=n;j++){
                dp[k][i][j]=s[j-1]-'0';
            }
        }
    }
    for(ll i=1;i<=2*n;i++){
        for(ll j=1;j<=2*n;j++){
            boss[i][j]=(i+j)%2;
        }
    }
    vector<ll>v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    ll ans=1e9;
    do{
        for(ll i=1;i<=n;i++)for(ll j=1;j<=n;j++)temp[i][j]=dp[v[0]][i][j];
        for(ll i=1;i<=n;i++)for(ll j=1;j<=n;j++)temp[i][j+n]=dp[v[1]][i][j];
        for(ll i=1;i<=n;i++)for(ll j=1;j<=n;j++)temp[i+n][j]=dp[v[2]][i][j];
        for(ll i=1;i<=n;i++)for(ll j=1;j<=n;j++)temp[i+n][j+n]=dp[v[3]][i][j];
        ll x=0,y=0;
        for(ll i=1;i<=2*n;i++)for(ll j=1;j<=2*n;j++)x+=(temp[i][j]==boss[i][j])?1:0;
        for(ll i=1;i<=2*n;i++)for(ll j=1;j<=2*n;j++)y+=(temp[i][j]!=boss[i][j])?1:0;
        ans=min(ans,min(x,y));
    } while(next_permutation(v.begin(),v.end()));
    cout<<ans<<endl;
    return 0;
}
/*
3
101
010
101

101
000
101

010
101
011

010
101
010
*/
