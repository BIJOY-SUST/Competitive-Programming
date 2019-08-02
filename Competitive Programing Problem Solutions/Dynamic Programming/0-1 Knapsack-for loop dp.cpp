#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define mx             100010
#define inf            0x3f3f3f3f
#define mod            1000000007
#define PI             2*acos(0.0)
#define E              2.71828182845904523536
#define ll             long long int
#define ull            unsigned long long int
#define pii            pair<int,int>
#define pll            pair<ll,ll>
#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
#define fast           ios_base::sync_with_stdio(false),cin.tie(NULL)
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
template <typename T> bool bitcheck(T p,T pos){return (bool)(p&(1<<pos));}
template <typename T> T biton(T p,T pos){return p=p|(1<<pos);}
template <typename T> T bitoff(T p,T pos){return p=p&~(1<<pos);}
template <typename T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
template <typename T> T POW(T b,T p) {T Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
template <typename T> T BigMod(T b,T p,T Mod) {T Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
template <typename T> T ModInverse(T p,T Mod) {return BigMod(p,Mod-2,Mod);}
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//********************************************Code Start Here*********************************************************//

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
    fast;
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        int n,w;
        scanf("%d%d",&n,&w);
        for(int i=1;i<=n;i++)
            scanf("%d%d",&ob[i].weight,&ob[i].value);
        int ans=knapsack(n,w);
        printf("Case %d: %d\n",cs,ans);
    }
    return 0;
}
/**
Input:
3

4 6
3 2
4 3
2 4
3 4

5 10
1 120
7 400
4 280
3 150
4 200

3
50
10 20 30
160 100 120

Output:
Case 1: 8
Case 2: 600
Case 3: 180
**/
