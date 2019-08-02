#include<bits/stdc++.h>

using namespace std;

#define mx             10010
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
int dp[mx];
void grandy(){
    dp[0]=dp[1]=dp[2]=0;
    int mark[mx/2+10];
    for(int i=3;i<mx;i++){
        mem(mark,0);
        for(int j=1;j<(i+1)/2;j++){
            mark[dp[j]^dp[i-j]]=1;
        }
        int ret=0;
        while(mark[ret]==1) ret++;

        dp[i]=ret;
    }
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    grandy();
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        int n;
        scanf("%d",&n);
        int ans=0;
        for(int i=1;i<=n;i++){
            int d;
            scanf("%d",&d);
            ans^=dp[d];
        }
        printf("Case %d: ",cs);
        if(ans!=0) printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}
