#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
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


//Aho Corasick
//Time Complexity:
//𝑂(𝑛)
//Space Complexity for index of all occurrences:
//𝑂(𝑚√𝑚),𝑤ℎ𝑒𝑟𝑒 𝑚=𝑠𝑢𝑚 𝑜𝑓 𝑎𝑙𝑙 𝑝𝑎𝑡𝑡𝑒𝑟𝑛𝑠

const int N=5000;
///beware! if k distinct patterns are given having sum of length m then size of ending array and oc array will
///be at most m.sqrt(m) ,But for similar patterns one must act with them differently
struct aho_corasick
{
    ll link[N]; ///A suffix link for a vertex p is a edge that points to
///the longest proper suffix of the string corresponding to the vertex p.
    ll psz; ///tracks node numbers of the trie.
    ll to[N][20]; ///tracks the next node.
    vll ending[N]; ///ending[i] stores the indexes of patterns which ends at node i(from the trie).
    vll oc[N]; ///oc[i] stores ending index of all occurrences of pattern[i]
///so real oc[i][j]=oc[i][j]-pattern[i].size()+1,0-indexed.
    ll cnt[N],path[N],endof[N],len;///for number of occurrences.
    vll no;
    ll dp[20][N][2][2];

    void clear()
    {
        for(int i = 0; i < psz; i++)
            cnt[i]=0,path[i]=0, endof[i]=0,link[i] = 0,ending[i].clear(),oc[i].clear();
        mem(to,0);
        psz = 0;
        len=0;
    }
    aho_corasick()
    {
        psz = N - 2;
        clear();
    }
    void add_word(int idx)
    {
        ll u = 0;
        for(int c: no)
        {
            if(!to[u][c]) to[u][c] = ++psz;
            u = to[u][c];
        }
        ending[u].eb(idx);
        endof[idx]=u;
    }
    void populate(int cur)
    {
/// merging the occurrences of patterns ending at cur node in the trie
        for(auto occ: ending[link[cur]])
        {
            ending[cur].eb(occ);
        }

    }
    void push_links()
    {
        queue<ll> q;
        ll u, v, w;
        char c;
        q.push(0);
        link[0] = -1;
        while(!q.empty())
        {
            u = q.front();
            q.pop();
            for(int i=0;i<10;i++)
            {
                if(!to[u][i]) continue;
                v = to[u][i];
                c = i;
                w = link[u];
                while(w != -1 && !to[u][c]) w = link[w];
                if(w != -1) link[v] = to[w][c];
                else link[v] = 0;
                q.push(v);
                populate(v);
//                path[len++]=v;
            }
        }
    }

//    void populate(vi &en, int cur){
//        for(auto idx: en){
//            oc[idx].eb(cur);
//        }
//    }
//    void traverse(string s){
//        ll n=s.size();
//        ll cur=0;///root
//        for(int i=0; i<n; i++){
//            char c=s[i];
//            while(cur!=-1 && !to[u][c]) cur=link[cur];
//            if(cur!=-1) cur=to[cur][c];
//            else cur=0;
//            populate(ending[cur],i);
//            cnt[cur]++;
//        }
//        for(int i=len-1; i>=0; i--) cnt[link[path[i]]]+=cnt[path[i]];
//    }


    void make_vec(ll num)
    {
        no.clear();
        while(num)
        {
            ll rem=num%10;
            num=num/10;
            no.pb(rem);
        }
        reverse(all(no));
    }
    ll lol(int pos,int state,int isSmall,int isBeautiful)
    {
        if(pos==no.size()) return isBeautiful;

        ll &ret=dp[pos][state][isSmall][isBeautiful];
        if(ret!=-1) return ret;
//        debug(pos);
        ret=0;
        ll lo=0,hi;
        if(isSmall) hi=9;
        else hi=no[pos];

        for(int dgt=lo;dgt<=hi;dgt++)
        {
            int nStat=state;

            while(nStat!=-1 and to[nStat][dgt]==0)
            {
                nStat=link[nStat];
            }
            if(nStat!=-1) nStat=to[nStat][dgt];
            else nStat=0;

            ret+=lol(pos+1,nStat,isSmall|(dgt<hi),isBeautiful|(ending[nStat].size()>0));
        }
        return ret;

    }
    ll lol2(int pos,int state,int isSmall,int isBeautiful)
    {
        mem(dp,-1);
        return lol( pos, state, isSmall, isBeautiful);

    }

};



aho_corasick t;
int main()
{
    t.clear();
//    mem(dp,-1);
    ll l,r,k,n;
    cin>>l>>r>>k>>n;
    for(int i=1; i<=n; i++)
    {
        ll d;
        cin>>d;
        t.make_vec(d);
        t.add_word(i);
    }
    t.push_links();

//    for(int i=1;i<=t.psz;i++){
//        cout<<"i "<<i<<" "<<t.link[i]<<nl;
//    }

    t.make_vec(l-1);
    ll Left=t.lol2(0,0,0,0);

//    cout<<Left<<nl;

    ll le=l,ri=r;
    ll ans=-1;
    while(le<=ri){
        ll mid=(le+ri)>>1;
        t.make_vec(mid);
//        debug(mid);
//        mem(dp,-1);
        ll Right=t.lol2(0,0,0,0);
//        debug(Right);
        if(Right-Left>=k){
            ans=mid;
            ri=mid-1;
        }
        else le=mid+1;
    }
    if(ans!=-1) cout<<ans<<nl;
    else cout<<"no such number"<<nl;





//    t.push_links();
//    t.traverse(s);
/////print all occurrences
//    for(i=0; i<m; i++)
//    {
//        cout<<t.oc[i].size()<<nl;
//        for(auto x:t.oc[i]) cout<<x-p[i].size()+1<<' ';
//        cout<<nl;
//    }
/////print number of occurrences
//    for(i=0; i<m; i++) cout<<t.cnt[t.endof[i]]<<' ';
//    cout<<nl;

    return 0;
}
/*


*/



