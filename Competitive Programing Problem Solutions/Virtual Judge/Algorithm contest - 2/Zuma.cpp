#include<bits/stdc++.h>

using namespace std;

#define mx             1001
#define inf            0x3f3f3f3f
#define mod            1000000007
#define PI             2*acos(0.0)
#define E              2.71828182845904523536
#define ll             long long int
#define ull            unsigned long long int
#define pii            pair<int,int>
#define pll            pair<ll,ll>
#define toint(s)       atoi(s.c_str())
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
///Code Start Here
using namespace std;
int n,mw;
int weight[mx],price[mx],dp[mx][mx];
int sieve(int x,int y){
    if(x==n+1) return 0;
    if(dp[x][y]!=-1) return dp[x][y];
    else{
        int ret1,ret2;
        if(y+weight[x]<=mw) ret1=sieve(x+1,y+weight[x])+price[x];
        else ret1=0;
        ret2=sieve(x+1,y);
        dp[x][y]=max(ret1,ret2);
//        cout<<dp[x][y]<<endl;
        return dp[x][y];
    }
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){

        memset(weight,0,sizeof(weight));
        memset(price,0,sizeof(price));
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int p,w;
            scanf("%d %d",&p,&w);
            price[i]=p;
            weight[i]=w;
        }
        int g,ans=0;
        scanf("%d",&g);
        for(int i=1;i<=g;i++){
            scanf("%d",&mw);
            memset(dp,-1,sizeof(dp));
            ans+=sieve(1,0);
        }
        printf("%d\n",ans);
    }
    return 0;
}

