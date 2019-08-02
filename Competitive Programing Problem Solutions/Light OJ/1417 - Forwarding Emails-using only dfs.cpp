#include<bits/stdc++.h>

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
#define one(x)         __builtin_popcount(x)
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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int road[mx];
int vis[mx],boss[mx];
int dfs(int u){
    vis[u]=1;
    int cnt=0;
    if(road[u]!=-1&&vis[road[u]]==0){
        cnt+=1+dfs(road[u]);
    }
    vis[u]=0;
    return boss[u]=cnt;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    ll t;
    scanf("%lld",&t);
    for(ll cs=1;cs<=t;cs++){
        mem(vis,0);
        mem(road,-1);
        mem(boss,-1);
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            int u,v;
            cin>>u>>v;
            road[u]=v;
        }
        int ans=0,ind;
        for(int i=1;i<=n;i++){
            if(boss[i]==-1){
                int d=dfs(i);
//                cout<<i<<" "<<d<<endl;
                if(d>ans){
                    ans=d;
                    ind=i;
                }
            }
        }
        printf("Case %lld: ",cs);
        cout<<ind<<endl;
    }
    return 0;
}

