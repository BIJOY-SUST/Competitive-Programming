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
#define mx             1001
//#define mod            1000000007
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
using namespace std;
int n,w;
int weight[mx],price[mx],dp[mx][mx];
int sieve(int x,int y){
    if(x==n+1) return 0;
    if(dp[x][y]!=-1) return dp[x][y];
    else{
        int ret1,ret2;
        if(y+weight[x]<=w) ret1=sieve(x+1,y+weight[x])+price[x];
        else ret1=0;
        ret2=sieve(x+1,y);
        dp[x][y]=max(ret1,ret2);
//        cout<<dp[x][y]<<endl;
        return dp[x][y];
    }
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
//        int n,w;
        memset(dp,-1,sizeof(dp));
        memset(weight,0,sizeof(weight));
        memset(price,0,sizeof(price));
        scanf("%d %d",&n,&w);
        for(int i=1;i<=n;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            weight[i]=x;
            price[i]=y;
        }
        int ans=sieve(1,0);
        printf("Case %d: %d\n",tc,ans);
    }
    return 0;
}
