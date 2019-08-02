//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;

//#define mx             100010
//#define inf            0x3f3f3f3f
//#define mod            1000000007
//#define PI             2*acos(0.0)
//#define E              2.71828182845904523536
//#define ll             long long int
//#define ull            unsigned long long int
//#define pii            pair<int,int>
//#define pll            pair<ll,ll>
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
//#define fast           ios_base::sync_with_stdio(false),cin.tie(NULL)
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
template <typename T> bool bitcheck(T p,T pos){return (bool)(p&(1<<pos));}
template <typename T> T biton(T p,T pos){return p=p|(1<<pos);}
template <typename T> T bitoff(T p,T pos){return p=p&~(1<<pos);}
//template <typename T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
//template <typename T> T POW(T b,T p) {T Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
//template <typename T> T BigMod(T b,T p,T Mod) {T Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
//template <typename T> T ModInverse(T p,T Mod) {return BigMod(p,Mod-2,Mod);}
//template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//********************************************Code Start Here*********************************************************//
int a[18][18],dp[18][(1<<16)+5];
int n;
int boss(int s,int p){
//    if(s==n) return 0;
    if(p==((1<<n)-1));
    int &ret=dp[s][p];
    if(ret!=-1) return ret;
    int mm=0;
    for(int i=0;i<n;i++){
        if(!bitcheck(p,i)){
            mm=max(mm,boss(s+1,biton(p,i))+a[s][i]);
        }
    }
    return ret=mm;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        mem(dp,-1);
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&a[i][j]);
            }
        }
        int ans=boss(0,0);
        printf("Case %d: %d\n",cs,ans);
    }
    return 0;
}
/*

*/
