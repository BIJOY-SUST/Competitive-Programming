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
string tostr(ll n)     {stringstream rr;rr<<n;return rr.str();}
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
bool bitcheck(ll p,ll pos){return (bool)(p&(1<<pos));}
template <typename T> T biton(T p,T pos){return p=p|(1<<pos);}
template <typename T> T bitoff(T p,T pos){return p=p&~(1<<pos);}
template <typename T> T POW(T b,T p) {T Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
template <typename T> T BigMod(T b,T p,T Mod) {T Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
template <typename T> T ModInverse(T p,T Mod) {return BigMod(p,Mod-2,Mod);}
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//********************************************Code Start Here*********************************************************//
vector<int>arr;
int dp[101][101];
int sumItoJ(int i,int j){
    int sum=0;
    for(int k=i;k<=j;k++){
        sum+=arr[k];
    }
    return sum;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    int n;
    while(scanf("%d",&n)!=EOF){
        mem(dp,0);
        arr.clear();
        for(int i=0;i<n;i++){
            int k; scanf("%d",&k);
            arr.push_back(k);
        }

        for(int i=0;i<n;i++) dp[i][i]=arr[i];
        for(int d=1;d<n;d++){
            for(int i=0;i<n-d;i++){
                int j=i+d;
                int cost=1e9;
                for(int k=i;k<=j;k++){
                    int temp_sum=sumItoJ(i,j)+((k>i)?dp[i][k-1]:0)+((k<j)?dp[k+1][j]:0);
                    if(temp_sum<cost){
                        cost=temp_sum;
                    }
                }
                dp[i][j]=cost;
//                cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
        }
        printf("Cost of Optimal BST is %d\n",dp[0][n-1]);
    }
    return 0;
}
/*
4
4 2 6 3
*/

