#include<bits/stdc++.h>
//#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define ll             long long int
//#define pp             pair<int,int>
//#define bug(x)         printf("X: %d\n",x)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//int biton(int n,int pos){return n=n|(1<<pos);}
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
//ll POW(ll b,ll p) {ll r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
//ll BigMod(ll b,ll p,ll m) {ll r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
//ll ModInverse(ll n,ll m) {return BigMod(n,m-2,m);}
using namespace std;
int a[25],b[25];
int n;
//bool vis[25][25];
int dp[25][25];
int lcs(int i,int j){
    if(i==n+1||j==n+1){
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=0;
    if(a[i]==b[j]) ans=1+lcs(i+1,j+1);
    else{
        int ret1=lcs(i+1,j);
        int ret2=lcs(i,j+1);
        ans=max(ret1,ret2);
    }
//    vis[i][j]=true;
    dp[i][j]=ans;
    return dp[i][j];
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    scanf("%d",&n);
    mem(a,0);
    int k;
    for(int i=1;i<=n;i++){
        scanf("%d",&k);
        a[k]=i;
    }
    mem(b,0);
//    mem(vis,false);
    while(scanf("%d",&k)==1){
        b[k]=1;
        for(int i=2;i<=n;i++){
            scanf("%d",&k);
            b[k]=i;
        }
        mem(dp,-1);
        int ans=lcs(1,1);
        printf("%d\n",ans);
        mem(b,0);
    }
    return 0;
}
/*

*/
