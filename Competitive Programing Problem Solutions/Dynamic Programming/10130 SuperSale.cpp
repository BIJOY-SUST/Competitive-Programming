/*
BIJOY
CSE-25th Batch
Shahjalal University of Science and Technology
*/
#include<bits/stdc++.h>
//#define pi             3.14159265358979323846264338328
//#define pi             acos(-1)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mx             1001
//#define mod            100000007
//const long long inf =  1e15;
/*----------------------Graph Moves------------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
/*---------------------------------------------------*/
/*-----------------------Bitmask---------------------*/
//int Set(int N,int pos){return N=N(1<<pos);}
//int reset(int N,int pos){return N=N&~(1<<pos);}
//bool check(int N,int pos){return (bool)(N&(1<<pos));}
/*---------------------------------------------------*/
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
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
//        int n,w;
//        memset(dp,-1,sizeof(dp));
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
//        printf("Case %d: %d\n",tc,ans);
        printf("%d\n",ans);
    }
    return 0;
}

