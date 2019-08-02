#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

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
#define ull             unsigned long long
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
//#define rev(v)          reverse(v.begin(),v.end())
//#define srt(v)          sort(v.begin(),v.end())
//#define grtsrt(v)       sort(v.begin(),v.end(),greater<int>())
//#define all(v)          v.begin(),v.end()
//#define valid(tx,ty)    tx>=0&&tx<r&&ty>=0&&ty<c
//#define mem(arr,val)    memset(arr,val,sizeof(arr))
//#define Unique(x)       x.erase(unique(x.begin(),x.end()),x.end())
//#define forstl(it,v)    for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)
//#define fast            ios_base::sync_with_stdio(false),cin.tie(NULL)

//template <typename T> bool bitcheck(T p,T pos){return (bool)(p&(1<<pos));}
//template <typename T> T biton(T p,T pos){return p=p|(1<<pos);}
//template <typename T> T bitoff(T p,T pos){return p=p&~(1<<pos);}
//template <typename T> T POW(T b,T p) {T Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
//template <typename T> T BigMod(T b,T p,T Mod) {T Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
//template <typename T> T ModInverse(T p,T Mod) {return BigMod(p,Mod-2,Mod);}
//template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//ll ext_gcd(ll a,ll b,ll *x,ll *y){if(a==0){*x=0;*y=1;return b;}ll x1,y1;ll gcd = ext_gcd(b%a,a,&x1,&y1);*x=y1-(b/a)*x1;*y=x1;return gcd;}
//#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
//void deb(istream_iterator<string> it) {}
//template<typename T, typename... Args> void deb(istream_iterator<string> it, T a, Args... args) {cerr << *it << " = " << a << endl;deb(++it, args...);}

const int fx[]      = {+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]      = {-1,+1,+0,+0,+1,+1,-1,-1};
const int mx        = 1e5+10;
const int inf       = 0x3f3f3f3f;
const int mod       = 10007;
const double pi         = 2*acos(0.0);
const double E          = 2.71828182845904523536;
const double eps        = 1e-9;
bool mark[mx];vector<int>prime;
void sieve(){memset(mark,true,sizeof(mark));for(int i=3;i<=(int)sqrt(mx);i+=2){if(mark[i]){for(int j=i*i;j<=mx;j+=2*i) mark[j]=false;}}prime.push_back(2);for(int i=3;i<=mx;i+=2) if(mark[i]) prime.push_back(i);}
///code start here

struct mat{
    ull v[5][5];
};
mat zero,I;

void matrix_mul(mat &a,mat &b){
    mat sol=zero;
    for(ull i=0;i<2;i++){
        for(ull j=0;j<2;j++){
            sol.v[i][j]=0;
            for(ull k=0;k<2;k++){
                sol.v[i][j]+=(a.v[i][k]*b.v[k][j]);
            }
        }

    }
    a=sol;
}

mat love(mat org,ull n){
    mat x=I,y=org;
    while(n){
        if(n&1) matrix_mul(x,y);
        matrix_mul(y,y);
        n>>=1;
    }
    return x;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    for(ull i=0;i<2;i++){
        for(ull j=0;j<2;j++){
            zero.v[i][j]=0;
        }
    }
    I=zero;
    for(ull i=0;i<2;i++) I.v[i][i]=1;
    ull t,cs=1;
    sf("%lld",&t);
    while(t--){
        ull p,q,n;
        sf("%llu%llu%llu",&p,&q,&n);
        if(n<=0){
            pf("Case %llu: %llu\n",cs++,2ull);
            continue;
        }
        else if(n==1){
            pf("Case %llu: %llu\n",cs++,p);
            continue;
        }

        mat org=zero;
        org.v[0][0]=p;
        org.v[0][1]=-q;
        org.v[1][0]=1;
        org.v[1][1]=0;
        mat ans=love(org,n-1);
        ull sum=(ans.v[0][0]*p+ans.v[0][1]*2);
        pf("Case %llu: %llu\n",cs++,sum);
//        cs++;
    }
    return 0;
}
/*

*/
