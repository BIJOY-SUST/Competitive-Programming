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
ll n,k;
ll Rabin_Karp(string text){
    ll len=text.size();
    ll b=247;
    vector<ll>p_pow(len);
    p_pow[0]=1;
    for(ll i=1;i<len;i++){
        p_pow[i]=(p_pow[i-1]*b);
    }
    vector<ll>val(len+1,0);
    for(ll i=0;i<len;i++){
        val[i+1]=(val[i]+(text[i])*p_pow[i]);
//        cout<<val[i+1]<<endl;
    }
    set<ll>ans;
    for(int i=0;i<=len-k;i++){
        ll text_hash=(val[i+k]-val[i]);
        text_hash=(text_hash*p_pow[n-i-1]);///        text_hash=(text_hash*p_pow[n-i-k]) is also valid;
//        cout<<text_hash<<endl;
        ans.insert(text_hash);
    }
    return ans.size();
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    fast;
    ll t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        string text;
        cin>>text;
        ll ans=Rabin_Karp(text);
        cout<<ans<<'\n';
    }
    return 0;
}
/*
5
7 3
dogodog
*/
