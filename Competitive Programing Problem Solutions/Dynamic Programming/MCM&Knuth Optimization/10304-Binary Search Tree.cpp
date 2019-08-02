///First Code is geeksforgeeks Type
///Second Code is Knuth Optimization
/*
.
.
.
.
.
.
.
.
.
.
.
.*/
//#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//using namespace std;
//
//#define mx             100010
//#define inf            0x3f3f3f3f
//#define mod            1000000007
//#define PI             2*acos(0.0)
//#define E              2.71828182845904523536
//#define ll             long long int
//#define ull            unsigned long long int
//#define pii            pair<int,int>
//#define pll            pair<ll,ll>
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define mem(arr,val)   memset(arr,val,sizeof(arr))
//#define fast           ios_base::sync_with_stdio(false),cin.tie(NULL)
//string tostr(ll n)     {stringstream rr;rr<<n;return rr.str();}
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//bool bitcheck(ll p,ll pos){return (bool)(p&(1<<pos));}
//template <typename T> T biton(T p,T pos){return p=p|(1<<pos);}
//template <typename T> T bitoff(T p,T pos){return p=p&~(1<<pos);}
//template <typename T> T POW(T b,T p) {T Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
//template <typename T> T BigMod(T b,T p,T Mod) {T Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
//template <typename T> T ModInverse(T p,T Mod) {return BigMod(p,Mod-2,Mod);}
//template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
////********************************************Code Start Here*********************************************************//
//int arr[301];
//int dp[301][301],sum[301];
//int sumItoJ(int i,int j){
//    if(i>j) return 0;
//    else return sum[j]-sum[i-1];
//}
//int main(){
////    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    int n;
//    while(scanf("%d",&n)!=EOF){
//        mem(dp,0);
//        for(int i=1;i<=n;i++){
//            scanf("%d",&arr[i]);
//        }
//        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+arr[i];
//        for(int d=1;d<n;d++){
//            for(int i=1;i<=n-d;i++){
//                int j=i+d;
//                int cost=1e9;
//                for(int k=i;k<=j;k++){
//                    int d1=sumItoJ(i,k-1)+sumItoJ(k+1,j);
//                    int d2=((k>i)?dp[i][k-1]:0)+((k<j)?dp[k+1][j]:0);
////                    cout<<"k = "<<k<<" -> "<<d1<<" "<<d2<<endl;
//                    if(d1+d2<cost){
//                        cost=d1+d2;
//                    }
//                }
//                dp[i][j]=cost;
////                cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
//            }
//        }
//        printf("%d\n",dp[1][n]);
//    }
//    return 0;
//}
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
int arr[301];
int dp[301][301],sum[301],mid[301][301];
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    int n;
    while(scanf("%d",&n)!=EOF){
        mem(dp,0);
        mem(sum,0);
        mem(arr,0);
        mem(mid,0);
        for(int i=1;i<=n;i++){
            scanf("%d",&arr[i]);
        }
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+arr[i],mid[i][i]=i;
        for(int d=1;d<n;d++){
            for(int i=1;i<=n-d;i++){
                int j=i+d;
                int cost=1e9,l=mid[i][j-1],r=mid[i+1][j];
                for(int k=l;k<=r;k++){
                    int d2=sum[j]-sum[i-1]-arr[k]+dp[i][k-1]+dp[k+1][j];
//                    cout<<"k = "<<k<<" -> "<<d1<<" "<<d2<<endl;
                    if(d2<cost){
                        cost=d2;
                        mid[i][j]=k;
                    }
                }
                dp[i][j]=cost;
//                cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
        }
        printf("%d\n",dp[1][n]);
    }
    return 0;
}
/*
Sample Input
1 5
3 10 10 10
3 5 10 20
Sample Output
0
20
20
*/
