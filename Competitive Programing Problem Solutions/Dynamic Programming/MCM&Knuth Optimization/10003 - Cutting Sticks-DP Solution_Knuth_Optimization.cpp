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

int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    int d,n,p[101],dp[101][101],val[101][101];
    while(scanf("%d",&d)&&d){
        mem(dp,0);
        mem(p,0);
        mem(val,0);
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&p[i]);
        }
        p[0]=0;
        p[n+1]=d;
//        for(int i=0;i<n+2;i++)
//            cout<<p[i]<<endl;
        for(int i=0;i<=n+1;i++) val[i][i]=i;
        for(int d=1;d<=n;d++){
            for(int i=1;i<=n+1-d;i++){
                int j=i+d;
                int ans=1e9,l=val[i][j-1],r=val[i+1][j];
//                cout<<"BIJOY "<<i<<" "<<j<<" "<<d<<" ";
//                cout<<l<<" "<<r<<endl;
                for(int k=l;k<=r;k++){
                    int temp=(dp[i][k]+dp[k+1][j]+p[j]-p[i-1]);
//                    cout<<"temp "<<k<<" "<<temp<<endl;
                    if(temp<ans){
                        ans=temp;
                        val[i][j]=k;
//                        cout<<"JOY "<<k<<endl;
                    }
                }
                dp[i][j]=ans;
//                cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
//                cout<<i<<" "<<j<<endl;
            }
        }
        printf("The minimum cutting is %d.\n",dp[1][n+1]);
    }
    return 0;
}
/*
Sample Input
100
3
25 50 75
10
4
4 5 7 8
0
Sample Output
The minimum cutting is 200.
The minimum cutting is 22.
*/


