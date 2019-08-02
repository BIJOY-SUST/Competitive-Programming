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
const double phi = 0.57721566490153286060651209;
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
        ll a,b,c,d;
        sf("%lld%lld%lld%lld",&a,&b,&c,&d);
        ll ans=1ll+__gcd(abs(a-c),abs(b-d));
        pf("Case %lld: %lld\n",cs,ans);
    }
    return 0;
}
/*

*/

/**
        *   At first lets simplify the problem. Lets assume that there exists n lattice points
        *   in between segment AB. If a lattice point breaks down a segment into two, then the
        *   answer = n + 1. we should take the absolute difference of x co-ordinate and y
        *   co-ordinate between these two points. That means we made the scenario originated.
        *   In co-ordinate, one of two points became (0,0). Lets name the new segment as A'B'
        *   Now, think, when does a lattice point come in this case while traversing from A'
        *   to B'? A lattice point comes when we pass an integer amount in x co-ordinate and
        *   at the same time we should pass an integer amount in y co-ordinate. If we found
        *   the first lattice point, then the distance between the lattice point and A' would
        *   be repeated until we reach B' and name this distance d. That means, we would get
        *   the second lattice point if we pass d distance from the first lattice point, third
        *   lattice point would be revealed by second and so on. It can be proved
        *   mathematically that this n is equal to GCD of(difference of x co-ordinate,
        *   difference of y co-ordinate between).
        *   Now, come to the mathematical view. Lets think about the segment A'B'. One of the
        *   two corner points is (0,0) and let the other is (p,q). Now, the equation for this
        *   line is y = (p/q)*x. Here, we should bring p/q to the least possible term. It can
        *   done by taking GCD(p,q) = G and y = ((p/G)/(q/G))*x.  From the points on the
        *   equation y = (p/q)*x, only those points would be counted as lattice points which
        *   are integers and its both x and y co-ordinates are less than p and q respectively.
        *   These points can obtain by  letting G ranging 1 to G in equation y=((p/G)/(q/G))*x.
        *   An example may clear the scenario. Lets consider three cases.
        *           1. (2,3),
        *           2. (4,6) and
        *           3. (6,9)
        *   The equation of these three lines are y = (2/3)*x, y = (4/6)*x and y = (6/9)*x
        *   respectively. Lets take their GCD and make them Least possible term. Here, GCD
        *   equals to 1, 2, 3 respectively and all of them indicates one single line y =
        *   (2/3)*x. But we would count 1, 2, 3 lattice points for the equation no 1, 2, 3
        *   respectively. Our answer is one more than this GCD, because we are missing point
        *   (0,0) in the scenario.
        *   Do some paper work if you could not understand the scenario till now.
        */
