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
const int mx        = 2e6+10;
const int inf       = 0x3f3f3f3f;
const ll  mod       = 1e9+7;
const double pi     = 2*acos(0.0);
const double E      = 2.71828182845904523536;
const double eps    = 1e-9;
///code start here
#define mxx 15000005


ll gcd(ll a, ll b){
    if (a == 0) return b;
    return gcd(b % a, a);
}
ll find_ged(ll arr[], ll n){
    ll res = arr[0];
    for (ll i = 1; i < n; i++) res = gcd(arr[i], res);
    return res;
}
ll prime[mxx], cnt[mxx];
void sieve(){
    for (ll i = 2; i * i < mxx; ++i){
        if (!prime[i])
            for (ll j = i * i; j < mxx; j += i)
                prime[j] = i;
    }
    for (ll i = 1; i < mxx; ++i)
        if (!prime[i])
            prime[i] = i;
}
ll lol(ll arr[], ll n){
    ll ans = 0;
    for (ll i=0; i < n; ++i){
        ll element = arr[i];
        while (element > 1){
            ll div = prime[element];
            debug(i,element,div);
            ++cnt[div];
            ans = max(ans, cnt[div]);
            while (element % div==0)
                element /= div;
        }
    }
    return ans;
}

int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    fast;
    sieve();
    ll n, cc=0;
    cin>>n;
    ll a[n], g, anss;
    for (ll i = 0; i < n; ++i) cin >> a[i];
    sort(a,a+n);
    g = find_ged(a, n);
    for (ll i = 0; i < n; ++i)a[i] = a[i]/g;
    anss = lol(a, n);
    if(anss==0){
      return cout << "-1"<<nl,0;
    }
    cout << n-anss<<nl;
    return 0;
}
