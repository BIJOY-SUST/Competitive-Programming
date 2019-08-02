#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
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
//template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//********************************************Code Start Here*********************************************************//
ll fact[35];
ll dp[35][35];
void func(){
    for(int n=0;n<35;n++){
        for(int k=0;k<35;k++){
            if(n<k){
                dp[n][k]=0;
            }
            else if(k==0){
                dp[n][k]=1;
            }
            else{
                dp[n][k]=dp[n-1][k]+dp[n-1][k-1];
            }
//            cout<<dp[n][k]<<" ";
        }
//        cout<<endl;
    }
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    fact[0]=1;
    for(ll i=1;i<35;i++){
        fact[i]=fact[i-1]*i;
    }
    ll t;
    func();
    scanf("%lld",&t);
    for(ll cs=1;cs<=t;cs++){
        ll n,k;
        scanf("%lld%lld",&n,&k);
        ll ans;
        if(k>n) ans=0;
        else   ans=dp[n][k]*dp[n][k]*fact[k];
        printf("Case %lld: %lld\n",cs,ans);
    }
    return 0;
}
/*

*/
