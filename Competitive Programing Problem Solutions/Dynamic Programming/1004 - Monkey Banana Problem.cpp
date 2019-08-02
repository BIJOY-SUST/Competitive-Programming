/*
BIJOY
CSE-25th Batch
Shahjalal University of Science and Technology
*/
#include<bits/stdc++.h>
//#define pi             3.14159265358979323846264338328
//#define pi             acos(-1)
#define valid(tx,ty)   tx>=0&&tx<2*n-1&&ty>=0&&ty<arr[tx].size()
//#define mx             1000001
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
//const int fx[]={+1,+1,+1};
//const int fy[]={+0,+1,-1};
//int arr[201][101];
//map<int,vector<int> >arr;
vector<int>arr[201];
int n,dp[201][101];
int sieve(int tx,int ty){
    if(valid(tx,ty)){
        if(dp[tx][ty]!=-1) return dp[tx][ty];
        if(tx<n)
        return dp[tx][ty]=max(sieve(tx-1,ty-1),sieve(tx-1,ty))+arr[tx][ty];
        else
        return dp[tx][ty]=max(sieve(tx-1,ty),sieve(tx-1,ty+1))+arr[tx][ty];
        //cout<<dp[tx][ty]<<endl;
    }
    else return 0;
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        scanf("%d",&n);
        for(int i=0;i<n*2-1;i++){
            if(i<n)
                for(int j=0;j<=i;j++){
                    int k;
                    scanf("%d",&k);
                    arr[i].push_back(k);
                }
            else
                for(int j=0;j<2*n-i-1;j++){
                    int k;
                    scanf("%d",&k);
                    arr[i].push_back(k);
                }
        }
//        for(int i=0;i<arr.size();i++){
//            for(int j=0;j<arr[i].size();j++){
//                printf("%d ",arr[i][j]);
//            }
//            printf("\n");
//        }
        memset(dp,-1,sizeof(dp));
        int ans=sieve(2*n-2,0);
        printf("Case %d: %d\n",tc,ans);
        for(int i=0;i<2*n;i++) arr[i].clear();
    }
    return 0;
}

