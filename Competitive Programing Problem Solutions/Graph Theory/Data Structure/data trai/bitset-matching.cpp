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
//bool mark[1000010];vector<int>prime;
//void sieve(){memset(mark,true,sizeof(mark));for(int i=3;i<=(int)sqrt(1000010);i+=2){if(mark[i]){for(int j=i*i;j<=1000010;j+=2*i) mark[j]=false;}}prime.push_back(2);for(int i=3;i<=1000010;i+=2) if(mark[i]) prime.push_back(i);}
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


///Bitset
///complexity n^2/64
vi v;
const int N=32;
bitset<N>bs[26],oc;
int main()
{
//    fast;
    int i,j,k,n,q,l,r;
    string s,p;
    getline(cin,s);
    for(i=0; s[i]; i++) bs[s[i]-'a'][i]=1;
    for(int h=0;h<s.length();h++){
        cout<<bs[s[h]-'a']<<nl;
    }
//    getchar();
    cin>>q;
    while(q--)
    {
//        getchar();
        cin>>p;
        oc.set();
        cout<<oc<<nl;
        for(i=0; p[i]; i++) {

            oc&=(bs[p[i]-'a']>>i);
            cout<<oc<<nl;
        }
        cout<<oc.count()<<nl;///number of occurences
        int ans=N,sz=p.size();
        int pos=oc._Find_first();
        v.pb(pos);
        pos=oc._Find_next(pos);
        while(pos<N)
        {
            v.pb(pos);
            pos=oc._Find_next(pos);
        }
        for(auto x:v) cout<<x<<' ';///position of occurences
        cout<<nl;
        v.clear();
        cin>>l>>r;///number of occurences from l to r,where l and r is 1-indexed
        if(sz>r-l+1) cout<<0<<nl;
        else cout<<(oc>>(l-1)).count()-(oc>>(r-sz+1)).count()<<nl;
//        cout<<(oc>>(l-1)).count()<<nl;
//        cout<<(oc>>(r-sz+1)).count()<<nl;
//        debug(p,q);
//        getchar();
    }
    return 0;
}