#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define     sfs(a)              scanf("%s", &a)
#define     sfi1(a)             scanf("%d", &a)
#define     sfi2(a, b)          scanf("%d %d", &a, &b)
#define     sfi3(a, b, c)       scanf("%d %d %d", &a, &b, &c)
#define     sfi4(a, b, c, d)    scanf("%d %d %d %d", &a, &b, &c, &d)
#define     sfd1(a)             scanf("%lf", &a)
#define     sfd2(a, b)          scanf("%lf %lf", &a, &b)
#define     sfd3(a, b, c)       scanf("%lf %lf %lf", &a, &b, &c)
#define     sfd4(a, b, c, d)    scanf("%lf %lf %lf %lf", &a, &b, &c, &d)
#define     sfll1(a)            scanf("%lld", &a)
#define     sfll2(a, b)         scanf("%lld %lld", &a, &b)
#define     sfll3(a, b, c)      scanf("%lld %lld %lld", &a, &b, &c)
#define     sfll4(a, b, c, d)   scanf("%lld %lld %lld %lld", &a, &b, &c, &d)
#define     sfull1(a)           scanf("%llu", &a)
#define     sfull2(a, b)        scanf("%llu %llu", &a, &b)
#define     sfull3(a, b, c)     scanf("%llu %llu %llu", &a, &b, &c)
#define     caseprint(case)     printf("Case %d: ", case ++)


#define nl              '\n'
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
const int mxn       = 2e6+10;
const int inf       = 0x3f3f3f3f;
const ll  mod       = 1e9+7;
const double pi     = 2*acos(0.0);
const double E      = 2.71828182845904523536;
const double eps    = 1e-9;
///code start here

struct node
{
    node* next[2];

    node()
    {
        next[0]=next[1]=NULL;
    }
}*root;
int sum[mxn];
void insert_num(int x)
{
    node* cur=root;
    int b;
    for(int i=31; i>=0; i--)
    {
        b=(x>>i)&1;
        if(cur->next[b]==NULL) cur->next[b]=new node();
        cur=cur->next[b];
    }
}
int get_max(int x)
{
    node* cur=root;
    int k,ans=0;
    for(int i=31; i>=0; i--)
    {
        k=(x>>i)&1;
        if(cur->next[!k]) cur=cur->next[!k],ans<<=1,ans++;
        else cur=cur->next[k],ans<<=1;
        debug(k,ans);
    }
    return ans;
}
int get_min(int x)
{
    node* cur=root;
    int k,ans=0;
    for(int i=31; i>=0; i--)
    {
        k=(x>>i)&1;
        if(cur->next[k]) cur=cur->next[k],ans<<=1;
        else cur=cur->next[!k],ans<<=1,ans++;
    }
    return ans;
}
void del(node* cur)
{
    for(int i=0; i<2; i++) if(cur->next[i]) del(cur->next[i]);
    delete(cur);
}
int main()
{
//fast;
    int i,j,k,n,m,t,cs=0;
    sfi1(t);
    while(t--)
    {
        root= new node();
        int mx=-inf,mn=inf;
        sfi1(n);
        sum[0]=0;
        for(i=1; i<=n; i++) sfi1(k),sum[i]=sum[i-1]^k;
        insert_num(0);
        for(i=1; i<=n; i++)
        {
            mx=max(mx,get_max(sum[i]));
            mn=min(mn,get_min(sum[i]));
//            debug(mx,mn);
            insert_num(sum[i]);
        }
        cout<<++cs<<nl;
        pf("%d %d\n",mx,mn);
        for(i=1; i<=n; i++) sum[i]=0;
        del(root);
    }
    return 0;
}
