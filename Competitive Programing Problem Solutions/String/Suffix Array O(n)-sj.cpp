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
template <typename T> T POW(T b,T p) {T Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
template <typename T> T BigMod(T b,T p,T Mod) {T Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
template <typename T> T ModInverse(T p,T Mod) {return BigMod(p,Mod-2,Mod);}
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





const int N = mxn;///maximum ASCII value of any character of the string
const int kinds = 128;///maximum ASCII value of any character of the string
char str[N];
int K, buc[N], r[N], sa[N], X[N], Y[N], high[N];
bool cmp(int *r, int a, int b, int x)
{
    return (r[a] == r[b] && r[a+x] == r[b+x]);
}
void suffix_array_DA(int n, int m)
{
    int *x = X, *y = Y, i, j, k = 0, l;
    memset(buc, 0, sizeof(buc));
    for(i = 0; i < n; i++) buc[ x[i]=str[i] ]++;
    for(i = 1; i < m; i++) buc[i] += buc[i-1];
    for(i = n-1; i >= 0; i--) sa[--buc[x[i]]] = i;
    for(l = 1, j = 1; j < n; m = j, l <<= 1)
    {
        j = 0;
        for(i = n-l; i < n; i++) y[j++] = i;
        for(i = 0; i < n; i++) if(sa[i] >= l) y[j++] = sa[i]-l;
        for(i = 0; i < m; i++) buc[i] = 0;
        for(i = 0; i < n; i++) buc[ x[y[i]] ]++;
        for(i = 1; i < m; i++) buc[i] += buc[i-1];
        for(i = n-1; i >= 0; i--) sa[ --buc[ x[y[i]] ]] = y[i];
        for(swap(x, y), x[sa[0]] = 0, i = 1, j = 1; i < n; i++)
            x[sa[i]] = cmp(y, sa[i-1], sa[i], l) ? j-1 : j++;
    }
    for(i = 1; i < n; i++) r[sa[i]] = i;
    for(i = 0; i < n-1; high[r[i++]] = k)
        for(k ? k--: 0, j = sa[r[i]-1]; str[i+k] == str[j+k]; k++);
}
vector<int> suffix_array_construction(string s)
{
    int n=s.size();
    for(int i=0; i<n; i++) str[i]=s[i];
    str[n]='\0';
    suffix_array_DA(n+1,kinds);
    vector<int>saa;
    for(int i=1; i<=n; i++) saa.eb(sa[i]);
    return saa;
}
vector<int> lcp_construction(string const& s, vector<int> const& p)
{
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++) rank[p[i]] = i;
    int k = 0;
    vector<int> lcp(n-1, 0);
    for (int i = 0; i < n; i++)
    {
        if (rank[i] == n - 1)
        {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k]) k++;
        lcp[rank[i]] = k;
        if (k) k--;
    }
    return lcp;
}
const int MX = 18;
int st[N][MX];
int lg[N];
void pre()
{
    lg[1] = 0;
    for (int i=2; i<N; i++)
        lg[i] = lg[i/2]+1;
}
void build(vector<int> &lcp)
{
    int n = lcp.size();
    for (int i=0; i<n; i++)
        st[i][0] = lcp[i];
    for (int k=1; k<MX; k++)
        for (int i=0; i<n; i++)
        {
            st[i][k] = st[i][k-1];
            int nxt = i + (1<<(k-1));
            if (nxt >= n) continue;
            st[i][k] = min(st[i][k], st[nxt][k-1]);
        }
}
///minimum of lcp[l.......r]
int get(int l, int r)
{
    int k = lg[r-l+1];
    return min(st[l][k], st[r-(1<<k)+1][k]);
}
int ra[N],sz;
///lcp of suffix starting from i and j
int lcp_(int i,int j)
{
    if(i==j) return sz-i;
    int l=ra[i];
    int r=ra[j];
    if(l>r) swap(l,r);
    return get(l,r-1);
}
string ss;
///lower bound of string t
int lb(string &t,vi &sa)
{
    int l=0,r=sz-1;
    int k=t.size();
    int ans=sz;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(ss.substr(sa[mid],min(sz-sa[mid],k)) >= t) ans=mid,r=mid-1;
        else l = mid+1;
    }
    return ans;
}
///upper bound of string t
int ub(string &t,vi &sa)
{
    int l=0,r=sz-1;
    int k=t.size();
    int ans=sz;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(ss.substr(sa[mid],min(sz-sa[mid],k)) > t) ans=mid,r=mid-1;
        else l = mid+1;
    }
    return ans;
}
int main()
{
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);

    fast;
    int i,j,k,n,m,q;
    string s;
    cin>>s;
    n = s.size();
    vector<int> sa = suffix_array_construction(s);
    vector<int> lcp = lcp_construction(s, sa);
    sz=n;
    ss=s;
    for(i=0; i<n; i++) ra[sa[i]]=i;
    pre();
    build(lcp);
    for(i=0; i<n; i++) cout<<sa[i]<<' ';
    cout<<nl;
    for(i=0; i<n-1; i++) cout<<lcp[i]<<' ';
    cout<<nl;
    cin>>q;
///lcp of suffixes
    while(q--)
    {
        cin>>i>>j;
        cout<<lcp_(i,j)<<nl;
    }
    cin>>q;
///number of occurrences of a pattern, not in sorted order
    while(q--)
    {
        string t;
        cin>>t;
        int l=lb(t,sa);
        int r=ub(t,sa);
        debug(l,r);
        for(i=l; i<r; i++) cout<<sa[i]<<' ';
        cout<<nl;
    }
    return 0;
}
/*

*/

