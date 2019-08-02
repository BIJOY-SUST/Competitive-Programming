#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define F               first
#define S               second
#define pb              push_back
#define pp              pop_back()
#define ui              unsigned int
#define ll              long long int
#define ull             unsigned long long int
#define ld              double
#define pii             pair<int,int>
#define pll             pair<ll,ll>
#define vi              vector<int>
#define vll             vector<ll>
#define vc              vector<char>
#define vs              vector<string>
#define vpii            vector<pii>
#define vpll            vector<pll>
#define mpii            map<int,int>
#define mpll            map<ll,ll>
#define ump             unordered_map
#define uset            unordered_set
#define PQ              priority_queue
#define nl              '\n'
#define pf              printf
#define sfc(a)          scanf("%c",&a)
#define sfs(a)          scanf("%s",&a)
#define sfi1(a)         scanf("%d",&a)
#define sfi2(a,b)       scanf("%d %d",&a,&b)
#define sfi3(a,b,c)     scanf("%d %d %d",&a,&b,&c)
#define sfi4(a,b,c,d)   scanf("%d %d %d %d",&a,&b,&c,&d)
#define sfd1(a)         scanf("%lf",&a)
#define sfd2(a,b)       scanf("%lf %lf",&a,&b)
#define sfd3(a,b,c)     scanf("%lf %lf %lf",&a,&b,&c)
#define sfd4(a,b,c,d)   scanf("%lf %lf %lf %lf",&a,&b,&c,&d)
#define sfll1(a)        scanf("%lld",&a)
#define sfll2(a,b)      scanf("%lld %lld",&a,&b)
#define sfll3(a,b,c)    scanf("%lld %lld %lld",&a,&b,&c)
#define sfll4(a,b,c,d)  scanf("%lld %lld %lld %lld",&a,&b,&c,&d)

#define sqr(a)              ((a)*(a))
#define dist(x1,y1,x2,y2)   sqrt(sqr(x1-x2)+sqr(y1-y2))
#define rev(v)              reverse(v.begin(),v.end())
#define srt(v)              sort(v.begin(),v.end())
#define grtsrt(v)           sort(v.begin(),v.end(),greater<int>())
#define all(v)              v.begin(),v.end()
#define one(x)              __builtin_popcount(x)
#define valid(tx,ty)        tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)        memset(arr,val,sizeof(arr))
#define Unique(x)           x.erase(unique(x.begin(),x.end()),x.end())
#define fast                ios_base::sync_with_stdio(false),cin.tie(NULL)
#define forstl(it,v)        for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define loop(i,n)           for(int i=0;i<n;i++)
#define loop1(i,n)          for(int i=1;i<=n;i++)

template <typename T> bool bitcheck(T p,T pos){return (bool)(p&(1<<pos));}
template <typename T> T biton(T p,T pos){return p=p|(1<<pos);}
template <typename T> T bitoff(T p,T pos){return p=p&~(1<<pos);}
template <typename T> ll toint(T s) {ll p;stringstream ss(s); ss>>p; return p;}
template <typename T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
template <typename T> T POW(T b,T p) {T Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
template <typename T> T BigMod(T b,T p,T Mod) {T Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
template <typename T> T ModInverse(T p,T Mod) {return BigMod(p,Mod-2,Mod);}
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args> void deb(istream_iterator<string> it, T a, Args... args) {cerr << *it << " = " << a << endl;deb(++it, args...);}

const int fx[]      = {+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]      = {-1,+1,+0,+0,+1,+1,-1,-1};
const int mx        = 5e5+10;
const int inf       = 0x3f3f3f3f;
const int mod       = 1e9+7;
const ld pi         = 2*acos(0.0);
const ld E          = 2.71828182845904523536;
const ld eps        = 1e-9;
ll fact[mx];
void factorial(){fact[0]=1;loop1(i,mx-1) fact[i]=(fact[i-1]*i)%mod;}
ll nCr(ll n,ll r){return (fact[n]*ModInverse(((ll)fact[n-r]*(ll)fact[r])%mod,(ll)mod))%mod;}
ll ext_gcd(ll a,ll b,ll *x,ll *y){if(a==0){*x=0;*y=1;return b;}ll x1,y1;ll gcd = ext_gcd(b%a,a,&x1,&y1);*x=y1-(b/a)*x1;*y=x1;return gcd;}
bool mark[mx];vector<int>prime;
void sieve(){memset(mark,true,sizeof(mark));for(int i=3;i<=(int)sqrt(mx);i+=2){if(mark[i]){for(int j=i*i;j<=mx;j+=2*i) mark[j]=false;}}prime.push_back(2);for(int i=3;i<=mx;i+=2) if(mark[i]) prime.push_back(i);}
///code start here

vll update[mx];
pair<int,int>jora[mx];
set<ll>ss;
mpll cnt;
bool flag[mx];
int par[mx],Rank[mx];
ll val[mx],ans[mx];

struct data{
    char ch;
    int ind;
};
data ob[mx];

int find_par(int x){
    if(x!=par[x]) par[x]=find_par(par[x]);
    return par[x];
}
void marge(int x,int y){
    par[y]=x;
    cnt[val[x]]--;
    if(cnt[val[x]]==0) ss.erase(val[x]);
    cnt[val[y]]--;
    if(cnt[val[y]]==0) ss.erase(val[y]);
    val[x]+=val[y];
    val[y]=0;
    cnt[val[x]]++;
    ss.insert(val[x]);
}
void Union(int x,int y){
    int pu=find_par(x);
    int pv=find_par(y);
    if(pu==pv) return;
    if(Rank[pu]>Rank[pv]){
        marge(pu,pv);
    }
    else{
        if(Rank[pu]==Rank[pv]) Rank[pv]++;
        marge(pv,pu);
    }
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    int n,m,q,x,y;
    cin>>n>>m>>q;
    loop1(i,n){
        cin>>x;
        update[i].pb(x);
    }
    loop1(i,m){
        int u,v;
        cin>>u>>v;
        jora[i]={u,v};
//        debug(jora[i].F,jora[i].S);
    }
    loop1(i,q){
        char ch2;
        cin>>ch2;
        if(ch2=='P'){
            cin>>x>>y;
            update[x].pb(y);
            ob[i].ch=ch2; ob[i].ind=x;
        }
        else{
            cin>>x;
            flag[x]=1;
            ob[i].ch=ch2; ob[i].ind=x;
        }
    }
    loop1(i,n){
        Rank[i]=0; par[i]=i;
        val[i]=update[i].back();
        cnt[val[i]]++;
        ss.insert(val[i]);
    }
    loop1(i,m){
        if(!flag[i]) Union(jora[i].F,jora[i].S);
    }
    for(int i=q;i>=1;i--){
        ans[i] = *(ss.rbegin());
        if(ob[i].ch=='D')
            Union(jora[ob[i].ind].F,jora[ob[i].ind].S);
        else{
            int root=find_par(ob[i].ind);
            cnt[val[root]]--;
            if(cnt[val[root]]==0) ss.erase(val[root]);
            val[root]-=update[ob[i].ind].back();
            update[ob[i].ind].pop_back();
            val[root]+=update[ob[i].ind].back();
            cnt[val[root]]++;
            ss.insert(val[root]);
        }
    }
    loop1(i,q) cout<<ans[i]<<nl;
    return 0;
}
/*
Input:
3 3 6
1 2 3
1 2
2 3
3 1
P 1 3
D 1
P 2 3
D 2
P 3 10
D 3

Output:
8
8
9
6
13
10
*/
