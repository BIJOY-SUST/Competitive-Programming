/*
BIJOY
CSE-25th Batch
Shahjalal University of Science and Technology
*/
#include<bits/stdc++.h>
//#define pi             3.14159265358979323846264338328
//#define pi             acos(-1)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define mx             1000001
#define mod            100000000
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
using namespace std;
int a,b,c,d;
long long int dp[101][101][11][11];
long long sieve(int n1,int n2,int k1,int k2){
    cout<<n1<<" "<<n2<<" "<<k1<<" "<<k2<<endl;
    if(n1<0||n2<0||k1<0||k2<0) return 0;
    if(n1==0&&n2==0) return 1;
    if(dp[n1][n2][k1][k2]!=-1) return dp[n1][n2][k1][k2];
    long long int ret1=sieve(n1-1,n2,k1-1,d);
    long long int ret2=sieve(n1,n2-1,c,k2-1);
    dp[n1][n2][k1][k2]=(ret1+ret2)%mod;
    return dp[n1][n2][k1][k2];
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    memset(dp,-1,sizeof(dp));
    scanf("%d %d %d %d",&a,&b,&c,&d);
    long long int ans=sieve(a,b,c,d);
    printf("%lld\n",ans);
    return 0;
}
