/*
#define lg2(n)          (31-__builtin_clz(n))

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
int weight[mx],price[mx],dp[mx][mx],dir[mx][mx];
int sieve(int x,int y){
    if(x==n+1) return 0;
    if(dp[x][y]!=-1) return dp[x][y];
    else{
        int ret1,ret2;
        if(y+weight[x]<=w) ret1=sieve(x+1,y+weight[x])+price[x];
        else ret1=0;
        ret2=sieve(x+1,y);
        if(ret1>ret2){
            dir[x][y]=1;
            return dp[x][y]=ret1;
        }
        else{
            dir[x][y]=2;
            return dp[x][y]=ret2;
        }
        //dp[x][y]=max(ret1,ret2);
//        cout<<dp[x][y]<<endl;
        //return dp[x][y];
    }
}
vector<int>sol;
int  print(int x,int y){
    if(dir[x][y]==-1) return 0;
    if(dir[x][y]==1){
        sol.push_back(x);
        return 1+print(x+1,y+weight[x]);
    }
    else return print(x+1,y);
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
//        int n,w;
        memset(dp,-1,sizeof(dp));
        memset(dir,-1,sizeof(dir));
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
//        for(int i=0;i<=n;i++){
//            for(int j=0;j<=w;j++){
//                printf("%d ",dp[i][j]);
//            }
//            cout<<endl;
//        }
        int total=print(1,0);
        printf("Total things %d\n",total);
        for(int i=0;i<sol.size();i++) printf("%d %d\n",weight[sol[i]],price[sol[i]]);
        sol.clear();
    }
    return 0;
}
/*
5
5 10
1 120
7 400
4 280
3 150
4 200

output
Case 1: 600
Total things 3
1 120
4 280
4 200
*/
