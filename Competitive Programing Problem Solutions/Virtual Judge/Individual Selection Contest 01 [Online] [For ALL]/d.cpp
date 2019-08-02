#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define nl              '\n'
#define sf              scanf
#define pf              printf
#define F               first
#define S               second
#define pb              push_back
#define eb              emplace_back
#define ui              unsigned int
#define ll              long long int
#define ull             unsigned long long int
#define pii             pair<int,int>
#define pll             pair<ll,ll>
#define vi              vector<int>
#define vll             vector<ll>
#define vpii            vector<pii>
#define vpll            vector<pll>
#define mpii            map<int,int>
#define mpll            map<ll,ll>
#define all(v)          v.begin(),v.end()
#define valid(tx,ty)    tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)    memset(arr,val,sizeof(arr))
#define Unique(x)       x.erase(unique(x.begin(),x.end()),x.end())
#define forstl(it,v)    for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define fast            ios_base::sync_with_stdio(false),cin.tie(NULL)
template <typename T> T POW(T b,T p) {T Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
template <typename T> T BigMod(T b,T p,T Mod) {T Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
template <typename T> T ModInverse(T p,T Mod) {return BigMod(p,Mod-2,Mod);}
typedef  tree<int, null_type, less<int >, rb_tree_tag, tree_order_statistics_node_update> o_set;
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args> void deb(istream_iterator<string> it, T a, Args... args) {cerr << *it << " = " << a << endl;deb(++it, args...);}
const int fx[]      = {+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]      = {-1,+1,+0,+0,+1,+1,-1,-1};
const int mx        = 1.5e7+10;
const int inf       = 0x3f3f3f3f;
const ll  mod       = 1e9+7;
const double pi     = 2*acos(0.0);
const double E      = 2.71828182845904523536;
const double eps    = 1e-9;
///code start here
    int f=0;

map<int,int>se;
vector<int>v;
vpll ans;
bool mark[mx];
int n;
void sieve()
{
    int c=0;
    for(int i=2; i<=(int)sqrt(mx); i+=1)
    {
        int cnt=0;
        if(mark[i])
        {
            c++;
            for(int j=2*i; j<=mx; j+=i){
                if(mark[j]==1){
                    cnt++;
                }
            }
//            if(c==n) continue;
            if(f and c==n-1) continue;
            int d=n-se[i];
            if(cnt==d){
                ans.eb(i,se[i]-1);
            }
        }

    }
}

int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    int n;
    cin>>n;
    int x;
    int dd=0;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x==1) dd++;
//        v.eb(x);
//        if(se.find(x)==se.end()){
            if(se[x]==0) se[x]=i+1;
//        }
        if(x==1){
            f=1;
        }
        mark[x]=1;
//        mp[x]++;

    }
    if(dd==n){
        return cout<<-1<<nl,0;
    }
//    sort(all(v));
//    Unique(v);

    if(f==1){
        ans.eb(1,1);
    }
    sieve();
    sort(all(ans));
//    reverse(all(ans));
    for(auto x:ans){
        cout<<x.F<<" "<<x.S<<nl;
    }
    int an=ans[ans.size()-1].S;
    int k=ans[ans.size()-1].F;
    if(k==1){
        cout<<-1<<nl;
    }
    else cout<<an<<nl;
//    debug(n);
    return 0;
}
