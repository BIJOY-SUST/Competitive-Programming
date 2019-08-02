#include<bits/stdc++.h>
#define mx             10010
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define ll             long long int
//#define pp             pair<int,int>
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//int biton(int p,int pos){return p=p|(1<<pos);}
//int bitoff(int p,int pos){return p=p&~(1<<pos);}
//bool bitcheck(int p,int pos){return (bool)(p&(1<<pos));}
//ll POW(ll b,ll p) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
//ll BigMod(ll b,ll p,ll Mod) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
//ll ModInverse(ll p,ll Mod) {return BigMod(p,Mod-2,Mod);}
using namespace std;
class bijoy{
public:
    int weight,value;
};
bijoy ob[mx];
int dp[mx][100];
int knapsack(int n,int wt){
    mem(dp,0);
    for(int i=0;i<=n;i++){
        for(int w=0;w<=wt;w++){
            if(i==0||w==0) dp[i][w]=0;
            else if(ob[i].weight>w){
                dp[i][w]=dp[i-1][w];
            }
            else{
                dp[i][w]=max(dp[i-1][w-ob[i].weight]+ob[i].value,dp[i-1][w]);
            }
//            cout<<dp[i][w]<<" ";
        }
//        cout<<endl;
    }
    return dp[n][wt];
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        int n,w;
        scanf("%d%d",&n,&w);
        for(int i=1;i<=n;i++)
            scanf("%d%d",&ob[i].weight,&ob[i].value);
        int ans=knapsack(n,w);
        printf("%d\n",ans);
    }
    return 0;
}
/**
Input:
5
4 6
3 2
4 3
2 4
3 4
Output:
0 0 0 0 0 0 0
0 0 0 2 2 2 2
0 0 0 2 3 3 3
0 0 4 4 4 6 7
0 0 4 4 4 8 8
8
**/
