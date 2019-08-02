/*______________________________________________
 !                   BIJOY                      !
 !               CSE-25th Batch                 !
 !Shahjalal University of Science and Technology!
 !______________________________________________!
*/
#include<bits/stdc++.h>
//#define pi             3.14159265358979323846264338328
//#define pi             acos(-1)
#define valid(tx,ty)   tx>=0&&tx<n&&ty>=0&&ty<n
//#define mx             1000001
//#define mod            100000007
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
using namespace std;
const int fx[]={+1,+1,+1};
const int fy[]={+0,+1,-1};
map<int,vector<int> >arr;
int n,dp[101][101];
int sieve(int tx,int ty){
    if(valid(tx,ty)){
        if(dp[tx][ty]!=-1) return dp[tx][ty];
        int ret=0;
        for(int i=0;i<3;i++){
            ret=max(ret,sieve(tx+fx[i],ty+fy[i])+arr[tx][ty]);
        }
        dp[tx][ty]=ret;
        return dp[tx][ty];
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
        for(int i=0;i<n;i++){
            for(int j=1;j<=n;j++){
                int k;
                scanf("%d",&k);
                arr[i].push_back(k);
            }
        }
//        for(int i=0;i<n;i++){
//            for(int j=0;j<n;j++){
//                printf("%d ",arr[i][j]);
//            }
//            printf("\n");
//        }
        memset(dp,-1,sizeof(dp));
        int ans=sieve(0,0);
        printf("Case %d: %d\n",tc,ans);
        for(int i=1;i<=n;i++) arr[i].clear();
    }
    return 0;
}

