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
const int mxn       = 2000010;
const int inf       = 0x3f3f3f3f;
const ll  mod       = 1e9+7;
const double pi     = 2*acos(0.0);
const double E      = 2.71828182845904523536;
const double eps    = 1e-9;
///code start here



                                    ///Suffix Array O(nlogn)
const int N=mxn;
/// Equivalence Class of every k-th step

vector<vector<int> >c;
vector<int>sort_cyclic_shifts(string const& s)
{
    int n = s.size();
    const int alphabet = 256;
    vector<int> p(n), cnt(alphabet, 0);
    c.clear();
    c.emplace_back();
    c[0].resize(n);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[0][p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[p[i]] != s[p[i-1]])
            classes++;


        c[0][p[i]] = classes - 1;
    }
    vector<int> pn(n), cn(n);
    cnt.resize(n);
    for (int h = 0; (1<<h) < n; h++)
    {
        for (int i = 0; i < n; i++)
        {
            pn[i] = p[i] - (1<<h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.end(), 0);
/// radix sort
        for (int i = 0; i < n; i++)
            cnt[c[h][pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[h][pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++)
        {
            pii cur = {c[h][p[i]], c[h][(p[i] + (1<<h))%n]};
            pii prev = {c[h][p[i-1]], c[h][(p[i-1] + (1<<h))%n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.push_back(cn);
    }
    return p;

}
vector<int> suffix_array_construction(string s)
{
    s += "!";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

/// compare two suffixes starting at i and j with length 2^k
int compare(int i, int j, int n, int k)
{
    pii a = {c[k][i], c[k][(i+1-(1<<k))%n]};
    pii b = {c[k][j], c[k][(j+1-(1<<k))%n]};
    return a == b ? 0 : a < b ? -1 : 1;
}
int lcp_(int i, int j)
{
    int log_n = c.size()-1;
    int ans = 0;
    for (int k = log_n; k >= 0; k--)
    {
        if (c[k][i] == c[k][j])
        {
            ans += 1 << k;
            i += 1 << k;
            j += 1 << k;
        }


    }
    return ans;
}

vector<int> lcp_construction(string const& s, vector<int> const& p)
{
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        rank[p[i]] = i;
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
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
    return lcp;
}

const int K = 22;
int st[N][K];
int lg[N];
int lnt[N];
int id[N];
int ps[N];

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
    for (int k=1; k<K; k++){
        for (int i=0; i<n; i++)
        {
            st[i][k] = st[i][k-1];
            int nxt = i + (1<<(k-1));
            if (nxt >= n)
                continue;
            st[i][k] = min(st[i][k], st[nxt][k-1]);
        }
    }
}

///minimum of lcp[l.......r]
int min_lcp(int l, int r)
{
    if(l>r) swap(l,r);
    r--;
    int k = lg[r-l+1];
    return min(st[l][k], st[r-(1<<k)+1][k]);
}
void lol(int &i,int &j,int l,int n){
    for(int k=lg[n];k>=0;k--){
        int _j=j+(1<<k);
        if(_j>=n) continue;
        if(min_lcp(i,_j)>=l) j=_j;
    }
    for(int k=lg[n];k>=0;k--){
        int _i=i-(1<<k);
        if(_i<0) continue;
        if(min_lcp(_i,j)>=l) i=_i;
    }
}
int main()
{
    fast;
    int n;
    pre();
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        string t;
        cin>>t;
        lnt[i]=t.size();
        if(i)s+=".";
        id[i]=s.size();
        s+=t;
    }

    vector<int> sa = suffix_array_construction(s);
    vector<int> lcp = lcp_construction(s, sa);
    build(lcp);

    for(int i=0;i<sa.size();i++){
        ps[sa[i]]=i;
    }

    int q;
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;

        x--;
        y--;

        int l;
        if(x==y){
            l=lnt[x];
        }
        else{
            l = min_lcp(ps[id[x]],ps[id[y]]);
            l=min(l,min(lnt[x],lnt[y]));
        }
        if(l==0){
            cout << 0 << "\n";
            continue;
        }

        x = ps[id[x]];
        y = ps[id[y]];
        if (x > y) swap(x, y);
        lol(x, y, l, s.size());

        cout << y-x+1 << "\n";
    }

    return 0;
}
/*

*/

