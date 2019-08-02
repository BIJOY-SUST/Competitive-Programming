/*______________________________________________
 !                   BIJOY                      !
 !               CSE-25th Batch                 !
 !Shahjalal University of Science and Technology!
 !______________________________________________!
*/
#include<bits/stdc++.h>
//#define pi             3.14159265358979323846264338328
//#define pi             acos(-1)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define mx             1000001
//#define mod            100000007
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
using namespace std;
typedef unsigned long long int u64;
u64 dp[25][10010];
int price[25];
u64 make;
u64 sieve(u64 x,u64 y){
    if(x>=21){
        if(y==make) return 1;
        else return 0;
    }
    if(dp[x][y]!=-1) return dp[x][y];
    else{
        u64 ret1,ret2;
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
    for(int i=1;i<=21;i++){
        price[i-1]=i*i*i;
    }
//    for(int i=0;i<21;i++) printf("%d ",price[i]);
    while(scanf("%llu",&make)==1){
        memset(dp,-1,sizeof(dp));
        u64 ans=sieve(0,0);
        printf("%llu\n",ans);
    }
    return 0;
}
///a  most optimization solution....

//#include<bits/stdc++.h>
//using namespace std;
//int main(){
//    int n;
//    long long dp[10001]={};
//    dp[0]=1;
//    for(int i=1;i*i*i<=10000;i++){
//        for(int j=i*i*i;j<=10000;j++){
//            dp[j]+=dp[j-i*i*i];
//        }
//    }
//    while(scanf("%d",&n)==1) printf("%lld\n",dp[n]);
//    return 0;
//}
