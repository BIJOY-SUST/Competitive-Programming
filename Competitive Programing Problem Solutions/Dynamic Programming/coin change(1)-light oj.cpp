//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;

#define mx             100010
#define inf            0x3f3f3f3f
#define mod            100000007
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

using namespace std;
long long int dp[51][1001];
int price[51],times[51];
int n,k;
long long int sieve(int x,int y){
    if(x==n+1){
        if(y==k) return 1;
        else return 0;
    }
    if(y==k) return 1;
    if(dp[x][y]!=-1) return dp[x][y];
    else{
        int ret1=0,ret2;
        for(int i=1;i<=times[x];i++){
            if(y+price[x]*i<=k)
                ret1+=sieve(x+1,y+price[x]*i);
            else break;
        }
        ret2=sieve(x+1,y);
        dp[x][y]=(ret1+ret2)%mod;
        return dp[x][y]%mod;
    }
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
//        int n,k;
        scanf("%d %d",&n,&k);
        memset(dp,-1,sizeof(dp));
        memset(price,0,sizeof(price));
        memset(times,0,sizeof(times));
        for(int i=1;i<=n;i++){
            scanf("%d",&price[i]);
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&times[i]);
        }
        int ans=sieve(1,0)%mod;
        printf("Case %d: %d\n",tc,ans);
    }
    return 0;
}

