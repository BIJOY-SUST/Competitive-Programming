#include<bits/stdc++.h>
//#define pi             3.14159265358979323846264338328
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define ll             long long int
//#define llu            unsigned long long int
#define mx             30005
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
ll n;
int price1[]={2,3};
ll dp[3][mx];
ll sieve(int x,ll y){
    if(x>=11){
        if(y==n) return 1;
        else return 0;
    }
    if(dp[x][y]!=-1) return dp[x][y];
    else{
        ll ret1,ret2;
        for(int i=0;i<2;i++){
            if(y+price1[i]<=n) ret1=sieve(i,y+price1[i]);
            else ret1=0;
        }
        ret2=sieve(x+1,y);
        dp[x][y]=ret1+ret2;
        return dp[x][y];
    }
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    while(scanf("%lld",&n)==1&&n){
        memset(dp,-1,sizeof(dp));
//        cout<<m<<endl;
        ll ans=sieve(0,0);
        printf("%lld\n",ans);
    }
    return 0;
}
