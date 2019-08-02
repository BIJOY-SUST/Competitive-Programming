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
#define Unique(x)       x.erase(unique(x.begin(),x.end()),x.end())
//#define forstl(it,v)    for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define fast            ios_base::sync_with_stdio(false),cin.tie(NULL)

template <typename T> bool bitcheck(T p,T pos){return (bool)(p&(1<<pos));}
template <typename T> T biton(T p,T pos){return p=p|(1<<pos);}
template <typename T> T bitoff(T p,T pos){return p=p&~(1<<pos);}
template <typename T> T POW(T b,T p) {T Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
template <typename T> T BigMod(T b,T p,T Mod) {T Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
template <typename T> T ModInverse(T p,T Mod) {return BigMod(p,Mod-2,Mod);}
//template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
//void deb(istream_iterator<string> it) {}
//template<typename T, typename... Args> void deb(istream_iterator<string> it, T a, Args... args) {cerr << *it << " = " << a << endl;deb(++it, args...);}
const int fx[]      = {+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]      = {-1,+1,+0,+0,+1,+1,-1,-1};
const int mx        = 1e6+10;
const int inf       = 0x3f3f3f3f;
const int mod       = 1e9+7;
const double pi         = 2*acos(0.0);
const double E          = 2.71828182845904523536;
const double eps        = 1e-9;
const double phi         = 0.57721566490153286060651209;
bool mark[mx];vector<int>prime;
void sieve(){memset(mark,true,sizeof(mark));for(int i=3;i<=(int)sqrt(mx);i+=2){if(mark[i]){for(int j=i*i;j<=mx;j+=2*i) mark[j]=false;}}prime.push_back(2);for(int i=3;i<=mx;i+=2) if(mark[i]) prime.push_back(i);}
///code start here


double arr[mx];
void har(){
    arr[1]=1.0;
    for(int i=2;i<=1e6;i++){
        arr[i]=arr[i-1]+1.0/i;
    }
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    har();
    int t;
    sf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        int a;
        sf("%d",&a);
        double ans;
        if(a<=1e6){
            ans=arr[a];
        }
        else{
            ans=log(a+0.5)+phi;
        }
        pf("Case %d: %.10f\n",cs,ans);
    }
    return 0;
}
/*

Graph demonstrating a connection between harmonic numbers and the natural logarithm. The harmonic number Hn can be interpreted as a Riemann sum of the integral: {\displaystyle \int _{1}^{n+1}{\frac {dx}{x}}=\ln(n+1).} {\displaystyle \int _{1}^{n+1}{\frac {dx}{x}}=\ln(n+1).}
The nth harmonic number is about as large as the natural logarithm of n. The reason is that the sum is approximated by the integral

{\displaystyle \int _{1}^{n}{1 \over x}\,dx} \int _{1}^{n}{1 \over x}\,dx
whose value is ln(n).

The values of the sequence Hn - ln(n) decrease monotonically towards the limit

{\displaystyle \lim _{n\to \infty }\left(H_{n}-\ln n\right)=\gamma ,} \lim _{n\to \infty }\left(H_{n}-\ln n\right)=\gamma ,
where γ ≈ 0.5772156649 is the Euler–Mascheroni constant. The corresponding asymptotic expansion as n → +∞ is

{\displaystyle H_{n}\sim \ln {n}+\gamma +{\frac {1}{2n}}-\sum _{k=1}^{\infty }{\frac {B_{2k}}{2kn^{2k}}}=\ln {n}+\gamma +{\frac {1}{2n}}-{\frac {1}{12n^{2}}}+{\frac {1}{120n^{4}}}-\cdots ,} H_{n}\sim \ln {n}+\gamma +{\frac {1}{2n}}-\sum _{k=1}^{\infty }{\frac {B_{2k}}{2kn^{2k}}}=\ln {n}+\gamma +{\frac {1}{2n}}-{\frac {1}{12n^{2}}}+{\frac {1}{120n^{4}}}-\cdots ,
where {\displaystyle B_{k}} B_{k} are the Bernoulli numbers.
*/
