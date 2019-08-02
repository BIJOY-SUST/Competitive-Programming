#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <iostream>
#include <cmath>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cstring>
using namespace std;

///Faster I/O
#define     sfs(a)              scanf("%s",&a)
#define     sfi1(a)             scanf("%d",&a)
#define     sfi2(a,b)           scanf("%d %d",&a,&b)
#define     sfi3(a,b,c)         scanf("%d %d %d",&a,&b,&c)
#define     sfi4(a,b,c,d)       scanf("%d %d %d %d",&a,&b,&c,&d)
#define     sfd1(a)             scanf("%lf",&a)
#define     sfd2(a,b)           scanf("%lf %lf",&a,&b)
#define     sfd3(a,b,c)         scanf("%lf %lf %lf",&a,&b,&c)
#define     sfd4(a,b,c,d)       scanf("%lf %lf %lf %lf",&a,&b,&c,&d)
#define     sfll1(a)            scanf("%lld",&a)
#define     sfll2(a,b)          scanf("%lld %lld",&a,&b)
#define     sfll3(a,b,c)        scanf("%lld %lld %lld",&a,&b,&c)
#define     sfll4(a,b,c,d)      scanf("%lld %lld %lld %lld",&a,&b,&c,&d)
#define     sfull1(a)           scanf("%llu",&a)
#define     sfull2(a,b)         scanf("%llu %llu",&a,&b)
#define     sfull3(a,b,c)       scanf("%llu %llu %llu",&a,&b,&c)
#define     caseprint(case)     printf("Case%d: ",case ++)

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
#define fast            ios_base::sync_with_stdio(0),cin.tie(0)
ll POW(ll b,ll p) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
ll BigMod(ll b,ll p,ll Mod) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
ll ModInverse(ll p,ll Mod) {return BigMod(p,Mod-2,Mod);}
//typedef  tree<int, null_type, less<int >, rb_tree_tag, tree_order_statistics_node_update> o_set;
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args> void deb(istream_iterator<string> it, T a, Args... args) {cerr << *it << " = " << a << endl;deb(++it, args...);}


//bool mark[1000010];vector<int>prime;
//void sieve(){memset(mark,true,sizeof(mark));for(int i=3;i<=(int)sqrt(1000010);i+=2){if(mark[i]){for(int j=i*i;j<=1000010;j+=2*i) mark[j]=false;}}prime.push_back(2);for(int i=3;i<=1000010;i+=2) if(mark[i]) prime.push_back(i);}
const int fx[]      = {+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]      = {-1,+1,+0,+0,+1,+1,-1,-1};
const int mxn       = 2e6;
const int inf       = 0x3f3f3f3f;
const ll  mod       = 1e9+7;
const double pi     = 2*acos(0.0);
const double E      = 2.71828182845904523536;
const double eps    = 1e-9;
///code start here



///37. Lyndon Factorization

///Complexity: 𝑂(𝑛)
///A string is called simple (or a Lyndon word), if it is strictly smaller than
///any of its own nontrivial suffixes. Examples of simple strings are: a, b, ab, aab, abb, ababb,
///abcd. It can be shown that a string is simple, if and only if it is strictly smaller
///than all its nontrivial cyclic shifts.
///Next,let there be a given string s. The Lyndon factorization of the
///string s is a factorization s=w1w2…wk, where all strings wi are simple,
///and they are in non-increasing order w1>=w2>=....>=wk.
///It can be shown, that for any string such a factorization exists and that it is unique.
///Here we use Duval algorithm for finding lyndon factorization
vector<string> duval(string const& s)
{
    int n = s.size();
    int i = 0;
    vector<string> factorization;
    while (i < n)
    {
        int j = i + 1, k = i;
        while (j < n && s[k] <= s[j])
        {
            if (s[k] < s[j])
                k = i;
            else
                k++;
            j++;
        }
        while (i <= k)
        {
            factorization.push_back(s.substr(i, j - k));
            i += j - k;
        }
    }
    return factorization;
}
string min_cyclic_string(string s)
{
    s += s;
    int n = s.size();
    int i = 0, ans = 0;
    while (i < n / 2)
    {
        ans = i;
        int j = i + 1, k = i;
        while (j < n && s[k] <= s[j])
        {
            if (s[k] < s[j])
                k = i;
            else
                k++;
            j++;
        }
        while (i <= k)
            i += j - k;
    }
    return s.substr(ans, n / 2);
}
int main()
{
    fast;
    ll i,j,k,n,m;
    string s;
    cin>>s;
    cout<<min_cyclic_string(s)<<nl;
    return 0;
}