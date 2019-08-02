/*
BIJOY
CSE-25th Batch
Shahjalal University of Science and Technology
*/
#include<bits/stdc++.h>
//#define pi             3.141592653589793238462643383
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define p              pair<int,int>
#define ll             long long int
//#define llu            unsigned long long int
#define mx             1005
#define mod            10056
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
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool check(int n,int pos){return (bool)(n&(1<<pos));}
/*---------------------------------------------------*/
using namespace std;
ll dp[mx][mx];
ll dp2[mx];
ll sieve(int n,int r){
    if(r==0||r==n) return 1;
    if(dp[n][r]!=-1) return dp[n][r];
    else{
        dp[n][r]=(sieve(n-1,r-1)%mod+sieve(n-1,r)%mod)%mod;
        return dp[n][r];
    }
}
ll race(int n){
    if(n==0) return 1;
    if(dp2[n]!=-1) return dp2[n];
    ll ret=0;
    for(int i=1;i<=n;i++){
        ret+=(sieve(n,i)*race(n-i))%mod;
        cout<<i<<" "<<ret<<endl;
        ret=ret%mod;
    }
    cout<<ret<<endl;
    return dp2[n]=ret;
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    memset(dp,-1,sizeof(dp));
    memset(dp2,-1,sizeof(dp2));

    for(int tc=1;tc<=t;tc++){
        int n;
        scanf("%d",&n);
        ll ans=race(n);
        printf("Case %d: %lld\n",tc,ans);
    }
    return 0;
}
/*
Sample Input
3
1
2
3
Sample Output
Case 1: 1
Case 2: 3
Case 3: 13
*/
