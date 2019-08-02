/*
BIJOY
CSE-25th Batch
Shahjalal University of Science and Technology
*/
///Accepted.............solution
///next solution will be optimization
#include<bits/stdc++.h>
//#define pi             3.14159265358979323846264338328
//#define pi             acos(-1)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define mx             10001
//#define mod            100000007
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
using namespace std;
int dp[6][7590],price[]={50,25,10,5,1};
int make;
int sieve(int x,int y){
    if(x>=5){
        if(y==make) return 1;
        else return 0;
    }
    if(dp[x][y]!=-1) return dp[x][y];
    else{
        int ret1,ret2;
        if(y+price[x]<=make) ret1=sieve(x,y+price[x]);
        else ret1=0;
        ret2=sieve(x+1,y);
        dp[x][y]=ret1+ret2;
        return dp[x][y];
    }
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    while(scanf("%d",&make)==1){
        memset(dp,-1,sizeof(dp));
        int ans=sieve(0,0);
        printf("%d\n",ans);
    }
    return 0;
}
