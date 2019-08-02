//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

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
#define toint(s)       atoi(s.c_str())
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
ll ami[mx],tumi[mx];
map<ll,ll>jor,bijor;
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        mem(ami,0);
        mem(tumi,0);
        jor.clear();
        bijor.clear();
        ll n;
        scanf("%lld",&n);
        for(ll i=0;i<n;i++){
            scanf("%lld",&ami[i]);
            tumi[i]=ami[i];
            if(i%2==0) jor[ami[i]]++;
            else  bijor[ami[i]]++;
        }
        sort(tumi,tumi+n);
        bool flag=true;
        ll ans;
        for(ll i=0;i<n;i++){
            bool f=false;
            if(i%2==0){
                if(jor[tumi[i]]>0){
                    f=true;
                    jor[tumi[i]]--;
                }
            }
            else if(i%2==1){
                if(bijor[tumi[i]]>0){
                    f=true;
                    bijor[tumi[i]]--;
                }
            }
            if(f==false){
                ans=i;
                flag=false;
                break;
            }
        }
        if(flag){
            printf("Case #%d: OK\n",cs);
        }
        else{
            printf("Case #%d: %lld\n",cs,ans);
        }
    }
    return 0;
}
