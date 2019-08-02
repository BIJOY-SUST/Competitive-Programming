#include<bits/stdc++.h>
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
//template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//********************************************Code Start Here*********************************************************//
ll fact[50];
ll dp[50][50];
ll sieve(ll r,ll c,ll k){
    if(r<k||c<k) return 0;
    if(k==0) return 1;

    if(dp[r][c]!=-1) return dp[r][c];
//    if(r==1) return c;
//    if(c==1) return r;
    else{
        dp[r][c]=r*sieve(r-1,c-1,k-1)+sieve(r,c-1,k);
        return dp[r][c];
    }
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    fact[0]=1;
    for(ll i=1;i<50;i++){
        fact[i]=fact[i-1]*i;
    }
    memset(dp,-1,sizeof(dp));
    ll t;
    scanf("%lld",&t);
    for(ll cs=1;cs<=t;cs++){
        ll n,k;
        mem(dp,-1);
        scanf("%lld%lld",&n,&k);
        if(k>n){
            printf("Case %lld: 0\n",cs);
        }
        else if(k==n){
            printf("Case %lld: %lld\n",cs,fact[n]);
        }
        else if(k==1){
            printf("Case %lld: %lld\n",cs,n*n);
        }
        else{
            ll ans=sieve(n,n,k);
            printf("Case %lld: %lld\n",cs,ans);
        }
    }
    return 0;
}
/*

*/

