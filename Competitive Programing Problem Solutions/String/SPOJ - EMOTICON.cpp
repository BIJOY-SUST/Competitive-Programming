//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
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
#include <string>
#include <string.h>

using namespace std;

///Faster I/O
#define     sfs(a)              scanf("%s",&a)
#define     sfi1(a)             scanf("%d",&a)
#define     sfi2(a,b)           scanf("%d%d",&a,&b)
#define     sfi3(a,b,c)         scanf("%d%d%d",&a,&b,&c)
#define     sfi4(a,b,c,d)       scanf("%d%d%d%d",&a,&b,&c,&d)
#define     sfd1(a)             scanf("%lf",&a)
#define     sfd2(a,b)           scanf("%lf%lf",&a,&b)
#define     sfd3(a,b,c)         scanf("%lf%lf%lf",&a,&b,&c)
#define     sfd4(a,b,c,d)       scanf("%lf%lf%lf%lf",&a,&b,&c,&d)
#define     sfll1(a)            scanf("%lld",&a)
#define     sfll2(a,b)          scanf("%lld%lld",&a,&b)
#define     sfll3(a,b,c)        scanf("%lld%lld%lld",&a,&b,&c)
#define     sfll4(a,b,c,d)      scanf("%lld%lld%lld%lld",&a,&b,&c,&d)
#define     sfull1(a)           scanf("%llu",&a)
#define     sfull2(a,b)         scanf("%llu%llu",&a,&b)
#define     sfull3(a,b,c)       scanf("%llu%llu%llu",&a,&b,&c)
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
#define fast            ios_base::sync_with_stdio(false),cin.tie(NULL)
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
const int mxn       = 5010;
const int inf       = 0x3f3f3f3f;
const ll  mod       = 1e9+7;
const double pi     = 2*acos(0.0);
const double E      = 2.71828182845904523536;
const double eps    = 1e-9;
///code start here

char text[200],str[200][200];
vector<int>vc[400010];
int nwnode[3000][130],backnode[3000],cnt[3000],vis[3000],id=0;

int no=1,len,dp[101][3000],ishere[101][3000];


int newnode()
{
    id++;
    for(int i=0; i<=128; i++)
    {
        nwnode[id][i]=0;
    }
    vis[id]=0;
    cnt[id]=0;
    vc[id].clear();
    return id;
}
void build(int n)
{
    int root=newnode(),p;
    queue<int>q;
    for(int i=1; i<=n; i++)
    {
        p=root;
        for(int j=0; str[i][j]; j++)
        {
            int c=str[i][j];
            if(!nwnode[p][c])
            {
                nwnode[p][c]=newnode();
            }
            p=nwnode[p][c];
        }
    }
    for(int i=0; i<=128; i++)
    {
        if(!nwnode[root][i]) nwnode[root][i]=root;
        else
        {
            q.push(nwnode[root][i]);
            backnode[nwnode[root][i]]=1;
        }
    }
    int u,v,w,c;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(int i=0; i<=128; i++)
        {
            if(!nwnode[u][i])
            {
                nwnode[u][i]=nwnode[backnode[u]][i];
                continue;
            }
            w=backnode[u];
            v=nwnode[u][i];
            while(nwnode[w][i]==0)
            {
                w=backnode[w];
            }
            int c=nwnode[w][i];
            backnode[v]=w=c;
            vc[v].pb(w);
            q.push(v);
        }
    }
}
void ahokoracik()
{
    int p=1,c;
    for(int i=0; text[i]; i++)
    {
        c=text[i];
        while(!nwnode[p][c]){
            p=backnode[p];
        }
        p=nwnode[p][c];
    }
    cnt[p]++;
}
int dfs(int p)
{
    if(vis[p]==1)
        return cnt[p];
    for(int i=0; i<vc[p].size(); i++)
    {
        int w=vc[p][i];

        cnt[p]+=dfs(w);
    }
    vis[p]=1;
    return cnt[p];
}



int lol(int pos,int en)
{
    if(pos==len) return 0;
    if(ishere[pos][en]==no) return dp[pos][en];
    ishere[pos][en]=no;
    int &ret=dp[pos][en];
    ret=10000000;
    ret=min(ret,lol(pos+1,1)+1);
    int en2=nwnode[en][text[pos]];
    if(cnt[en2]==0) ret=min(ret,lol(pos+1,en2));
    return ret;
}

int main()
{
    int k,l,m,n,p,c,test;
    while(1)
    {
        sfi2(n,m);
        if(n==0 and m==0) break;
        id=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%s",str[i]);
        }
        getchar();
        build(n);
        for(int i=1;i<=n;i++)
        {
            strcpy(text,str[i]);
            ahokoracik();
        }
        for(int i=1; i<=n; i++)
        {
            p=1;
            for(int j=0; str[i][j]; j++)
            {
                c=str[i][j];
                p=nwnode[p][c];
                l=dfs(p);
            }
            l=dfs(p);
        }
        int ans=0;

        for(int i=1;i<=m;i++)
        {
            fgets(text, 200, stdin);
//            gets(text);
            no++;
            len=strlen(text);
            ans+=lol(0,1);
//            debug(no,ans);
        }
        pf("%d\n",ans);
    }
    return 0;
}


