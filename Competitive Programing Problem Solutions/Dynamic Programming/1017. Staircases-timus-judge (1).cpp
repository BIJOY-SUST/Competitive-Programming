/*
BIJOY
CSE-25th Batch
Shahjalal University of Science and Technology
*/
#include<bits/stdc++.h>
//#define pi             3.14159265358979323846264338328
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define ll             long long int
//#define llu            unsigned long long int
#define mx             505
//#define mod            100000007
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
using namespace std;
ll dp[mx][mx];
int n;
//ll sieve(int prev,int remain){
//    if(remain==0) return 1;
//    if(remain<=prev) return 0;
//    if(dp[prev][remain]!=-1) return dp[prev][remain];
//    ll ret = 0;
//    for(int i=prev+1;i<=remain;i++) ret+=sieve(i,remain-i);
//    return dp[prev][remain]=ret;
//}
ll sieve(int prev,int remain){
    if(prev+1==remain) return 0;
    ll &ret = dp[prev][remain];
    if(ret!=-1) return ret;
    ret=0;
    for(int i=prev+1;i<=(int)(remain-1)/2;i++){
        ret=ret+sieve(i,remain-i)+1;
    }
    return ret;
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    memset(dp,-1,sizeof(dp));
    scanf("%d",&n);
    ll ans=sieve(0,n);
    printf("%lld\n",ans);
    return 0;
}
