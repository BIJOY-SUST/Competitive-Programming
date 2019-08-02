
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
        ll n;
        sf("%lld",&n);
        ll ans=0;
        pf("Case %lld: ",cs);

        if(n%9==0){
            pf("%lld %lld\n",n+(n/9)-1,n+(n/9));

        }
        else{
            pf("%lld\n",n+(n/9));
        }
    }
    return 0;
}
/*
http://rizoantoufiq.blogspot.com/2015/12/lightoj-1098-new-function.html
*/


/*

SOLUTION IDEA:
--------------

 Let, the given number is X = A - B. Here, B = A/10.
            So, A - A/10 = X
                A - (A-A%10)/10 = X
                10A - A + (A%10) = 10X
                9A = 10X - K , let K = A%10
                A = (10X - K)/9
                A = X + (X - K)/9
            For K equals to 0 to 9, if (X - K)%9 = 0, then A would be a solution.
            If we get a solution for K = 0, then we would also get a solution for
            K = 9 in this case. That means, if X%9 = 0, then there exists two solution.

*/
