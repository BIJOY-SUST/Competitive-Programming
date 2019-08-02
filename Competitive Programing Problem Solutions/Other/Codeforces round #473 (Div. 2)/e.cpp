#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

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
class edge{
public:
    ll w;
    ll u,v;
    bool operator<(const edge &p)const{
        return w<p.w;
    }
};
vector<edge>e;
map<ll,ll>representative;
ll find_par(ll x){
    if(representative[x]!=x) return representative[x]=find_par(representative[x]);
    return representative[x];
}
ll MST(ll n){
    sort(e.begin(),e.end());
    for(ll i=0;i<n;i++){
        representative[i]=i;
    }
    ll c=0,ans=0;
    for(ll i=0;i<(ll)e.size();i++){
        ll pu=find_par(e[i].u);
        ll pv=find_par(e[i].v);
        if(pu!=pv){
            representative[pu]=pv;
            c++;
            ans+=e[i].w;
            if(c==n-1){
                break;
            }
        }
    }
    return ans;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    ll n;
    for(n=2;n<=10;n++){
            e.clear();
    representative.clear();
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(i!=j){
                edge ob;
                ob.u=i;
                ob.v=j;
                ob.w=i^j;
                e.push_back(ob);
                edge ob2;
                ob2.u=j;
                ob2.v=i;
                ob2.w=j^i;
                e.push_back(ob2);
            }
        }
    }
    cout<<MST(n)<<endl;
    }
    return 0;
}
/*

*/
