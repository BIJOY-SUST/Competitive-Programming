/*
ঝুলে আছি নির্জনতায়, মৃত্যু কি অনিকেত প্রান্তর?
*/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
#define hi              cout<<"Hi, BIJOY...!"<<nl

ll POW(ll b,ll p) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
ll BigMod(ll b,ll p,ll Mod) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
ll ModInverse(ll p,ll Mod) {return BigMod(p,Mod-2,Mod);}
typedef  tree<int, null_type, less<int >, rb_tree_tag, tree_order_statistics_node_update> o_set;
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args> void deb(istream_iterator<string> it, T a, Args... args) {cerr << *it << " = " << a << endl;deb(++it, args...);}


//bool mark[1000010];vector<int>prime;
//void sieve(){memset(mark,true,sizeof(mark));for(int i=3;i<=(int)sqrt(1000010);i+=2){if(mark[i]){for(int j=i*i;j<=1000010;j+=2*i) mark[j]=false;}}prime.push_back(2);for(int i=3;i<=1000010;i+=2) if(mark[i]) prime.push_back(i);}
const int fx[]      = {+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]      = {-1,+1,+0,+0,+1,+1,-1,-1};
const int mxn       = 2e5;
const int inf       = 0x3f3f3f3f;
const ll  mod       = 1e9+7;
const double pi     = 2*acos(0.0);
const double E      = 2.71828182845904523536;
const double eps    = 1e-9;
///code start here



const int sz = mxn;
int num[sz], match, node, n_d, graph[30*sz][30], link[30*sz] ;
pii edge[30*sz] ;
int add_edge(int st,int ln)
{
    edge[n_d].F = st ;
    edge[n_d].S = ln ;
    for(int i=0 ; i<30 ; i++)
        graph[n_d][i] = 0 ;
    return n_d++;
}
void _jump(int pos)
{
    while(match > edge[graph[node][num[pos+1-match]]].S)
    {
        node = graph[node][num[pos+1-match]] ;
        match -= edge[node].S ;
    }
}
void add_char(int pos)
{
    int last = 0, a = num[pos], cur_ed, m_ed, u ;
    match++;
    while(match>0)
    {
        _jump(pos);
        cur_ed = num[pos - match + 1] ;
        int& v = graph[node][cur_ed] ;
        m_ed = num[edge[v].F + match - 1] ;
        if(v == 0)
        {
            v = add_edge(pos-match+1,mxn);//deb(pos,v);
            link[last] = node ;
            last = 0 ;
        }
        else if(a == m_ed)
        {
            link[last] = node ;
            return ;
        }
        else
        {
            u = add_edge(edge[v].F,match-1);
            graph[u][a] = add_edge(pos,mxn);
            graph[u][m_ed] = v ;
//if(edge[v].S<match-1) deb(v,edge[v].S,pos,match),wait;
            edge[v].F += match - 1;
            edge[v].S -= match - 1;
            v = u ;
            link[last] = u ;
            last = u ;
        }
        if(node == 0)
            match--;
        else
            node = link[node] ;
    }
}
void reset()
{
    node = 0 ;
    n_d = 0 ;
    match = 0 ;
    add_edge(0,mxn);
}
void print(int nd)
{
    if(nd)
        pf("%d %d %d\n",nd,edge[nd].F,edge[nd].S);
    for(int i=0 ; i<29 ; i++)
    {
        if(graph[nd][i] > 0)
        {
//            deb(nd,i);
            print(graph[nd][i]);
        }
    }
}
int main()
{
    string str ;
    cin>>str ;
    reset();
    for(int i=0 ; i<str.length() ; i++)
    {
        num[i] = str[i] - 'a' ;
        add_char(i);
    }
    print(0);
    return 0 ;
}

