/*BIJOY
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
int t,w,n,depth[50],coin[50],dp[50][1001],dir[50][1001];
vector<int>sol;
int sieve(int x,int y){
    if(x==n+1) return 0;
    if(dp[x][y]!=-1) return dp[x][y];
    else{
        int ret1,ret2;
        if(y+3*w*depth[x]<=t) ret1=sieve(x+1,y+3*w*depth[x])+coin[x];
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
    }
}
int sol_print(int x,int y){
    if(dir[x][y]==-1) return 0;
    else if(dir[x][y]==1){
        sol.push_back(x);
        return 1+sol_print(x+1,y+3*w*depth[x]);
    }
    else sol_print(x+1,y);
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    //int t,w;
    bool flag=false;
    while(scanf("%d %d",&t,&w)==2){
        //int n;
//        scanf("%d %d",&t,&w);
        if(flag==true) printf("\n");
        flag=true;
        memset(dp,-1,sizeof(dp));
        memset(dir,-1,sizeof(dir));
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d %d",&depth[i],&coin[i]);
        int ans=sieve(1,0);
        printf("%d\n",ans);
        int total=sol_print(1,0);
        printf("%d\n",total);
        for(int i=0;i<sol.size();i++){
            printf("%d %d\n",depth[sol[i]],coin[sol[i]]);
        }
        sol.clear();
        //printf("\n");
    }
    return 0;
}
