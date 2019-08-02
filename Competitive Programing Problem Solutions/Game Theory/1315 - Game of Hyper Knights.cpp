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
const int fx[]={-3,-2,-2,-1,-1,+1};
const int fy[]={-1,-1,+1,-2,-3,-2};
template <typename T> bool bitcheck(T p,T pos){return (bool)(p&(1<<pos));}
template <typename T> T biton(T p,T pos){return p=p|(1<<pos);}
template <typename T> T bitoff(T p,T pos){return p=p&~(1<<pos);}
template <typename T> ll toint(T s) {ll p;stringstream ss(s); ss>>p; return p;}
template <typename T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
template <typename T> T POW(T b,T p) {T Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
template <typename T> T BigMod(T b,T p,T Mod) {T Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
template <typename T> T ModInverse(T p,T Mod) {return BigMod(p,Mod-2,Mod);}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int dp[505][505];
int r=501,c=501;
int grandy(int x,int y){
    int &ret=dp[x][y];
    if(ret!=-1) return ret;
    int mark[10];
    mem(mark,false);
    for(int i=0;i<6;i++){
        int tx=x+fx[i];
        int ty=y+fy[i];
        if(valid(tx,ty)) mark[grandy(tx,ty)]=true;
    }
    int demo=0;
    while(mark[demo]) demo++;
    return ret=demo;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    mem(dp,-1);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        int n;
        scanf("%d",&n);
        int ans=0;
        for(int i=0;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            ans=ans^grandy(x,y);
        }
        printf("Case %d: ",cs);
        if(!ans) printf("Bob\n");
        else printf("Alice\n");
    }
    return 0;
}
