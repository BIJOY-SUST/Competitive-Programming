/*______________________________________________
 !                   BIJOY                      !
 !               CSE-25th Batch                 !
 !Shahjalal University of Science and Technology!
 !______________________________________________!
*/
#include<bits/stdc++.h>
//#define pi             3.14159265358979323846264338328
//#define pi             acos(-1)
//#define valid(tx,ty)   tx>=0&&tx<n&&ty>=0&&ty<3
//#define mx             1000001
//#define mod            100000007
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
using namespace std;
map<int,vector<int> >arr;
int n,dp[21][4];
int sieve(int tx){
    while(tx<=n){
        dp[tx][1]=min(dp[tx-1][2],dp[tx-1][3])+arr[tx-1][0];
        dp[tx][2]=min(dp[tx-1][1],dp[tx-1][3])+arr[tx-1][1];
        dp[tx][3]=min(dp[tx-1][1],dp[tx-1][2])+arr[tx-1][2];
        tx++;
    }
    return min(dp[n][1],min(dp[n][2],dp[n][3]));
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        //if(tc!=t) printf("\n");
//        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                int k;
                scanf("%d",&k);
                arr[i].push_back(k);
            }
        }
//        for(int i=0;i<n;i++){
//            for(int j=0;j<3;j++){
//                printf("%d ",arr[i][j]);
//            }
//            printf("\n");
//        }
        memset(dp,0,sizeof(dp));
        int ans=sieve(1);
        printf("Case %d: %d\n",tc,ans);
        for(int i=0;i<=n;i++) arr[i].clear();
    }
    return 0;
}
