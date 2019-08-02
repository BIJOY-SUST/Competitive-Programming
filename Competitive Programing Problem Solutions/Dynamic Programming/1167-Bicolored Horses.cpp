/*
BIJOY
CSE-25th Batch
Shahjalal University of Science and Technology
*/
#include<bits/stdc++.h>
//#define pi             3.14159265358979323846264338328
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define ll             long long int
//#define llu            unsigned long long int
//#define mx             1000001
//#define mod            100000007
//const long long inf =  1e15;
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
using namespace std;
int black[501],dp[501][501];
int sieve(int k,int n){
    if(k==0) return black[n]*(n-black[n]);
    //if(dp[k][n]!=-1) return dp[k][n];
    if(dp[k][n]==-1){
        for(int i=1;n-i>=k-1&&i<=n;++i){
            int ans=(black[n]-black[n-i])*(i-black[n]+black[n-i])+sieve(k-1,n-i);
            if(dp[k][n]==-1||ans<dp[k][n]) dp[k][n]=ans;
            //printf("%d %d %d\n",k,n,dp[k][n]);
        }
    }
    return dp[k][n];
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n,k;
    scanf("%d %d",&n,&k);
    black[0]=0;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        black[i+1]=black[i];
        if(x==1) ++black[i+1];
    }
    memset(dp,-1,sizeof(dp));
    int ans=sieve(k-1,n);
    printf("%d\n",ans);
    return 0;
}
