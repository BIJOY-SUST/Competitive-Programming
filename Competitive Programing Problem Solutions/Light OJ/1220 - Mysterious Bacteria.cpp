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

ll lol(ll n){
    ll ans=1,cnt;
    int ok=0;
    if(n<0) ok=1,n*=-1;
    for(ll i=2;i*i<=n;i++){
        if(n%i) continue;
        ll nn=n;
        cnt=0;
        while(nn%i==0){
            nn/=i;
            cnt++;
        }
        if(nn==1){
            if(ok==0||cnt%2) return cnt;
        }
    }
    return 1;
}

int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    sieve();
    int t;
    sf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        ll a;
        sf("%lld",&a);
        ll ans=lol(a);
        pf("Case %d: %lld\n",cs,ans);

    }
    return 0;
}
/*
http://pavelsimo.blogspot.com/2012/06/uva-10622-perfect-pth-powers.html
*/


/*
We say that x is a perfect square if, for some integer b, x=b2. The perfect pth power for a given number x is defined as  x=bp. You need to determine the largest p such that x is a perfect pth power.

This problem main idea is based on the understanding of the prime factors exponents divisibility. Let's begin with a proof that is going to help us  understand this concepts. Theorem: all the powers in the prime factorization of an integer n are even if and only if n is a perfect square, proof:
n=pk11pk22⋯pkttm=n2m=(pk11pk11)(pk22pk22)⋯(pkttpktt)m=pk1+k11pk2+k22⋯pkt+kttm=p2k11p2k22⋯p2ktt
Because all the exponents of m are even we can conclude that is perfect square.We can easily extend the previous proof to powers of 3, 4, ..., all the way to n. This means that if all the exponents in the prime factorization of a certain number x are divisible by a certain number p we can express this number as a pth power. To implement this idea we factorize the number in his standard prime factorization, and, for each factor frequency check the divisibility against certain number pth. If all the number pass the test we got our pth power, is guarantee to always get an answer because of the 1th powers.

The only thing left to consider is the cases when the number x is less than zero. Let's consider the following example 4096=212 but, -4096 is not (−2)12. In order to get a negative number as a result of repeated multiplication of the same number, we need to multiply that number odd times. Which means that in the case of negative number we stay with the biggest odd pth exponent as it shows in the following expression:

−4096⇒(−2)12⇒(−2)3⋅4⇒(−16)3
*/
