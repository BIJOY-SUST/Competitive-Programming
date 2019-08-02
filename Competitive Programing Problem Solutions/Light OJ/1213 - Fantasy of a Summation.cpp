
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
//
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;

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
#define ump             unordered_map
#define uset            unordered_set
#define PQ              priority_queue
#define nl              '\n'
#define pf              printf
#define sf              scanf
#define rev(v)          reverse(v.begin(),v.end())
#define srt(v)          sort(v.begin(),v.end())
#define grtsrt(v)       sort(v.begin(),v.end(),greater<int>())
#define all(v)          v.begin(),v.end()
#define valid(tx,ty)    tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)    memset(arr,val,sizeof(arr))
//#define Unique(x)       x.erase(unique(x.begin(),x.end()),x.end())
//#define forstl(it,v)    for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)
//#define fast            ios_base::sync_with_stdio(false),cin.tie(NULL)

template <typename T> bool bitcheck(T p,T pos){return (bool)(p&(1<<pos));}
template <typename T> T biton(T p,T pos){return p=p|(1<<pos);}
template <typename T> T bitoff(T p,T pos){return p=p&~(1<<pos);}
template <typename T> T POW(T b,T p) {T Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
ll BigMod(ll b,ll p,ll Mod)
{
    ll Ans=1;
    while(p)
    {
        if(p&1)Ans=(Ans*b)%Mod;
        b=(b*b)%Mod;
        p>>=1;
    }
    return Ans;
}
ll ModInverse(ll p,ll Mod)
{
    return BigMod(p,Mod-2,Mod);
}
//template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
//void deb(istream_iterator<string> it) {}
//template<typename T, typename... Args> void deb(istream_iterator<string> it, T a, Args... args) {cerr << *it << " = " << a << endl;deb(++it, args...);}
const int fx[]      = {+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]      = {-1,+1,+0,+0,+1,+1,-1,-1};
const ll mx        = 1e5+10;
const int inf       = 0x3f3f3f3f;
const ll mod       = 1e9+7;
const double pi         = 2*acos(0.0);
const double E          = 2.71828182845904523536;
const double eps        = 1e-9;
bool mark[mx];vector<ll>prime;
void sieve()
{
    memset(mark,true,sizeof(mark));
    for(ll i=3; i<=(ll)sqrt(mx); i+=2)
    {
        if(mark[i])
        {
            for(ll j=i*i; j<=mx; j+=2*i) mark[j]=false;
        }
    }
    prime.push_back(2);
    for(ll i=3; i<=mx; i+=2) if(mark[i]) prime.push_back(i);
}
///code start here



int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    sieve();
    ll t;
    sf("%lld",&t);
    for(ll cs=1;cs<=t;cs++){
        ll n,k,m;
        sf("%lld",&n);
        sf("%lld",&k);
        sf("%lld",&m);
        ll ans=0;
        for(ll i=1;i<=n;i++){
            ll d;
                    sf("%lld",&d);
            ans=(ans+d)%m;

        }
        ll dd=BigMod(n,k-1,m);
        dd=(dd*k)%m;
        ans=(dd*ans)%m;
        pf("Case %lld: %lld\n",cs,ans);

    }
    return 0;
}


/*
The title: Give you a cycle of summation, let you calculate the final result?

Idea: First of all, we have to make clear that in this loop, a[0]...a[n-1] appears as many times as
it is, and its large cumulative number is n^k.
Look at the second example:
it has 2 numbers, 3 layers of loop
1, a[0] a[0] a[0]
2, a[0] a[0] a[1]
3, a[0] a[1] a[0]
4, a[0] a[1] a[1]
5, a[1] a[0] a[0]
6, a[1] a[0] a[1]
7, a[1] a[1] a[0]
8, a[1] a[1] a[1]
in which the large cumulative number of times is 2^3=8 times, because each number The
number of accumulations of each number is as many as (n^k)*k/n=(n^(k-1))*k,
and the sum is equal to (sum(a[i])*(n) ^(k-1))*k)%mod
*/
