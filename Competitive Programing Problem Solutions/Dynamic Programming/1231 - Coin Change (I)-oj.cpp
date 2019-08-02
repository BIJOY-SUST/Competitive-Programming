/*
BIJOY
CSE-25th Batch
Shahjalal University of Science and Technology
*/
#include<bits/stdc++.h>
//#define pi             3.14159265358979323846264338328
//#define pi             acos(-1)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define mx             10001
#define mod            100000007
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
long long int dp[51][1001];
int price[51],times[51];
int n,k;
long long int sieve(int x,int y){
    if(x==n+1){
        if(y==k) return 1;
        else return 0;
    }
    //if(y==k) return 1;
    if(dp[x][y]!=-1) return dp[x][y];
    else{
        int ret1=0,ret2;
        for(int i=1;i<=times[x];i++){
            if(y+price[x]*i<=k)
                ret1+=sieve(x+1,y+price[x]*i);
            else ret1+=0;
        }
        ret2=sieve(x+1,y);
        dp[x][y]=(ret1+ret2)%mod;
        return dp[x][y]%mod;
    }
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
//        int n,k;
        scanf("%d %d",&n,&k);
        memset(dp,-1,sizeof(dp));
        memset(price,0,sizeof(price));
        memset(times,0,sizeof(times));
        for(int i=1;i<=n;i++){
            scanf("%d",&price[i]);
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&times[i]);
        }
        int ans=sieve(1,0)%mod;
        printf("Case %d: %d\n",tc,ans);
    }
    return 0;
}





























































///this is solution of using 3D array.....but TLE
///in above solution will be optimization
//*______________________________________________
// !                   BIJOY                      !
// !               CSE-25th Batch                 !
// !Shahjalal University of Science and Technology!
// !______________________________________________!
//*/
//#include<bits/stdc++.h>
////#define pi             3.14159265358979323846264338328
////#define pi             acos(-1)
////#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
////#define mx             10001
//#define mod            100000007
////const int fx[]={+1,-1,+0,+0};
////const int fy[]={+0,+0,+1,-1};
////const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
////const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
////const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
////const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//using namespace std;
//long long int dp[51][1001][51];
//int price[51],times[51];
//int n,k;
//long long int sieve(int x,int y,int ti){
//    if(x==n+1){
//        if(y==k) return 1;
//        else return 0;
//    }
//    if(y==k) return 1;
//    if(dp[x][y][ti]!=-1) return dp[x][y][ti];
//    else{
//        int ret1,ret2;
//        if(y+price[x]<=k&&times[x]>=ti)
//            ret1=sieve(x,y+price[x],ti+1);
//        else ret1=0;
//        ret2=sieve(x+1,y,1);
//        dp[x][y][ti]=(ret1+ret2)%mod;
//        return dp[x][y][ti]%mod;
//    }
//}
//int main(){
////    freopen("Input.txt","r",stdin);
////    freopen("Output.txt","w",stdout);
//    int t;
//    scanf("%d",&t);
//    for(int tc=1;tc<=t;tc++){
////        int n,k;
//        scanf("%d %d",&n,&k);
//        memset(dp,-1,sizeof(dp));
//        memset(price,0,sizeof(price));
//        memset(times,0,sizeof(times));
//        for(int i=1;i<=n;i++){
//            scanf("%d",&price[i]);
//        }
//        for(int i=1;i<=n;i++){
//            scanf("%d",&times[i]);
//        }
//        int ans=sieve(1,0,1)%mod;
//        printf("Case %d: %d\n",tc,ans);
//    }
//    return 0;
//}
//
