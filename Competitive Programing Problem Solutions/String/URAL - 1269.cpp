#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

///Faster I/O
#define     sfs(a)              scanf("%s",&a)
#define     sfi1(a)             scanf("%d",&a)
#define     sfi2(a,b)           scanf("d",&a,&b)
#define     sfi3(a,b,c)         scanf("d%d",&a,&b,&c)
#define     sfi4(a,b,c,d)       scanf("dd",&a,&b,&c,&d)
#define     sfd1(a)             scanf("%lf",&a)
#define     sfd2(a,b)           scanf("lf",&a,&b)
#define     sfd3(a,b,c)         scanf("lf%lf",&a,&b,&c)
#define     sfd4(a,b,c,d)       scanf("lflf",&a,&b,&c,&d)
#define     sfll1(a)            scanf("%lld",&a)
#define     sfll2(a,b)          scanf("lld",&a,&b)
#define     sfll3(a,b,c)        scanf("lld%lld",&a,&b,&c)
#define     sfll4(a,b,c,d)      scanf("lldlld",&a,&b,&c,&d)
#define     sfull1(a)           scanf("%llu",&a)
#define     sfull2(a,b)         scanf("llu",&a,&b)
#define     sfull3(a,b,c)       scanf("llu%llu",&a,&b,&c)
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
typedef  tree<int, null_type, less<int >, rb_tree_tag, tree_order_statistics_node_update> o_set;
//bool mark[1000010];vector<int>prime;
//void sieve(){memset(mark,true,sizeof(mark));for(int i=3;i<=(int)sqrt(1000010);i+=2){if(mark[i]){for(int j=i*i;j<=1000010;j+=2*i) mark[j]=false;}}prime.push_back(2);for(int i=3;i<=1000010;i+=2) if(mark[i]) prime.push_back(i);}
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args> void deb(istream_iterator<string> it, T a, Args... args) {cerr << *it << " = " << a << endl;deb(++it, args...);}
const int fx[]      = {+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]      = {-1,+1,+0,+0,+1,+1,-1,-1};
const int mxn       = 10000+100;
const int inf       = 0x3f3f3f3f;
const ll  mod       = 1e9+7;
const double pi     = 2*acos(0.0);
const double E      = 2.71828182845904523536;
const double eps    = 1e-9;
///code start here


const int N=mxn;
///beware! if k distinct patterns are given having sum of length m then size of ending array and oc array will
///be at most m.sqrt(m) ,But for similar patterns one must act with them differently
struct aho_corasick
{
    bool is_end[N];
    int link[N]; ///A suffix link for a vertex p is a edge that points to
///the longest proper suffix of
///the string corresponding to the vertex p.
    int psz; ///tracks node numbers of the trie
    map<char, int> to[N]; ///tracks the next node
    vi ending[N]; ///ending[i] stores the indexes of patterns which ends
///at node i(from the trie)
    vi oc[N]; ///oc[i] stores ending index of all occurrences of pattern[i]
///so real oc[i][j]=oc[i][j]-pattern[i].size()+1,0-indexed
    int cnt[N],path[N],ind[N],len;///for number of occurrences
    void clear()
    {
        for(int i = 0; i < psz; i++)
            is_end[i] = 0,cnt[i]=0,path[i]=0, ind[i]=0,link[i] = 0, to[i].clear(),ending[i].clear(),oc[i].clear();
        psz = 1;
        is_end[0] = 1;
        len=0;
    }
    aho_corasick()
    {
        psz = N - 2;
        clear();
    }
    void add_word(string s,int idx)
    {
        int u = 0;
        for(char c: s)
        {
            if(!to[u].count(c)) to[u][c] = psz++;
            u = to[u][c];
        }
        is_end[u] = 1;
        ending[u].eb(idx);
        ind[idx]=u;
//        debug(s,idx,u);
    }
    void populate(int cur)
    {
/// merging the occurrences of patterns ending at cur node in the trie
        for(auto occ: ending[link[cur]]){
            ending[cur].eb(occ);
//            debug(cur,occ);
        }

    }
    void push_links()
    {
        queue<int> q;
        int u, v, j;
        char c;
        q.push(0);
        link[0] = -1;
        while(!q.empty())
        {
            u = q.front();
            q.pop();
            for(auto it: to[u])
            {
                v = it.second;
                c = it.first;
                j = link[u];
                while(j != -1 && !to[j].count(c)) j = link[j];
                if(j != -1) link[v] = to[j][c];
                else link[v] = 0;
                q.push(v);
                populate(v);
                path[len++]=v;
//                debug(u,v,c,j,link[u],link[v]);
            }
        }
    }
    void populate(vi &en, int cur)
    {
/// occurrences of patterns in the given string
        for(auto idx: en)
        {
            oc[idx].eb(cur);
//            debug(idx,cur);
        }
    }
    void traverse(string s)
    {
        int n=s.size();
        int cur=0;///root
        for(int i=0; i<n; i++)
        {
            char c=s[i];
            while(cur!=-1 && !to[cur].count(c)) cur=link[cur];
            if(cur!=-1) cur=to[cur][c];
            else cur=0;
            populate(ending[cur],i);
            cnt[cur]++;
//            debug(c,cur,cnt[cur]);
        }
        for(int i=len-1; i>=0; i--) cnt[link[path[i]]]+=cnt[path[i]];
    }
};
aho_corasick t;
string p[N];
int cul[mxn];

int main(){

//    fast;
    t.clear();
    int i,j,k,n,m;
    string s="";
    cin>>m;
    for(i=0; i<m; i++){
        cin>>p[i];
        t.add_word(p[i],i);
    }
    cin>>n;
    mem(cul,0);
    vi dd;
    getchar();
    for(int i=1;i<=n;i++){
        string tem;
        getline(cin,tem);
        s+=tem;
        cul[i]+=tem.length()+cul[i-1];
        dd.pb(cul[i]);
//        debug(i,tem.length(),cul[i]);
        tem.clear();
    }
//    debug(s);
    t.push_links();
    t.traverse(s);
///print all occurrences
    vpii ans;

    for(i=0; i<m; i++)
    {

        for(auto x:t.oc[i]){
            ll gh=x-p[i].size()+1;
//            debug(i,gh);
//                cout<<x-p[i].size()+1<<' ';
            int ami=upper_bound(all(dd),gh)-dd.begin();
            ans.pb({ami+1,x-p[i].size()+2-cul[ami]});
//            debug(i,gh,ami);
        }
    }
    sort(all(ans));
    cout<<ans[0].F<<" "<<ans[0].S<<nl;
//    for(int i=0;i<ans.size();i++){
//        cout<<ans[i].F<<" "<<ans[i].S<<nl;
//    }

    return 0;
}
/*

*/



