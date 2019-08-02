#include<bits/stdc++.h>
#define mx             110
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
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
//ll POW(ll b,ll p) {ll r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
//ll BigMod(ll b,ll p,ll m) {ll r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
//ll ModInverse(ll n,ll m) {return BigMod(n,m-2,m);}
using namespace std;
int a[mx],b[mx],res,n,m;
int dp[mx][mx];
bool vis[mx][mx];
int lcs(int i,int j){
    if(i==n||j==m){
        return 0;
    }
    if(vis[i][j]) return dp[i][j];
    int ans=0;
    if(a[i]==b[j]) ans=1+lcs(i+1,j+1);
    else{
        int ret1=lcs(i+1,j);
        int ret2=lcs(i,j+1);
        ans=max(ret1,ret2);
    }
    vis[i][j]=true;
    dp[i][j]=ans;
    res=max(ans,res);
    return dp[i][j];
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int cs=1;
    while(scanf("%d%d",&n,&m)==2){
        if(n==0&&m==0) break;
        res=0;
        mem(a,0);
        mem(b,0);
        mem(vis,false);
        mem(dp,-1);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=0;i<m;i++){
            scanf("%d",&b[i]);
        }
        int ans=lcs(0,0);
        printf("Twin Towers #%d\n",cs++);
        printf("Number of Tiles : %d\n\n",ans);
    }

    return 0;
}
/*

*/
