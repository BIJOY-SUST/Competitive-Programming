//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

//#define _CRT_SECURE_NO_WARNINGS

#include<bits/stdc++.h>

//#include <ext/pb_ds/detail/standard_policies.hpp>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;

#define ll              long long int
#define ull             unsigned long long int
#define ld              long double

#define pii             pair<int,int>
#define pll             pair<ll,ll>
#define vi              vector<int>
#define vll             vector<ll>
#define vc              vector<char>
#define vs              vector<string>
#define vpii            vector<pii>
#define vpll            veetor<pll>
#define ppll            pair<ll,pll>
#define pllp            pair<pll,ll>
#define sti             stack<int>
#define stll            stack<ll>
#define qi              queue<int>
#define qll             queue<ll>
#define sei             set<int>
#define sell            set<ll>
#define ses             set<string>
#define pqll            priority_queue<ll>
#define pqgrt           priority_queue<ll,vector<ll>,greater<ll> >
#define mpii            map<int,int>
#define mpll            map<ll,ll>
#define mpsll           map<string,ll>
#define mplls           map<ll,string>
#define mpcll           map<char,ll>
#define umpii           unordered_map<int,int>
#define umpll           unordered_map<ll,ll>
#define umpsll          unordered_map<string,ll>
#define umplls          unordered_map<ll,string>
#define umpcll          unordered_map<char,ll>

#define pb              push_back
#define F               first
#define S               second
#define UB              upper_bound
#define LB              lower_bound

#define sf(a)           scanf("%d",&a)
#define sfl(a)          scanf("%lld",&a)
#define sfc(a)          scanf("%c",&a)
#define sff(a,b)        scanf("%d %d",&a,&b)
#define sffl(a,b)       scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)     scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)    scanf("%lld %lld %lld",&a,&b,&c)
#define pf              printf

#define rev(v)          reverse(v.begin(),v.end())
#define srt(v)          sort(v.begin(),v.end())
#define grtsrt(v)       sort(v.begin(),v.end(),greater<int>())
#define all(v)          v.begin(),v.end()
#define minv(v)         *min_element(v.begin(),v.end())
#define maxv(v)         *max_element(v.begin(),v.end())
#define cntv(v,a)       count(v.begin(),v.end(),a)

#define one(x)          __builtin_popcount(x)
#define valid(tx,ty)    tx>=0&&tx<n&&ty>=0&&ty<n
#define mem(arr,val)    memset(arr,val,sizeof(arr))
#define Unique(x)       x.erase(unique(x.begin(),x.end()),x.end())
#define fast            ios_base::sync_with_stdio(false),cin.tie(NULL)
#define forstl(x)       for(__typeof(x.begin()) it=(x.begin());it!=(x.end());++it)
#define loop(i,n)       for(int i=0;i<n;i++)
#define loop1(i,n)      for(int i=1;i<=n;i++)
#define case_print      printf("Case %d: ",cs)

const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};

template<class T1> void deb(T1 e1){cout<<e1<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}


ll ext_gcd(ll a,ll b,ll *x,ll *y){if(a==0){*x=0;*y=1;return b;}ll x1,y1;ll gcd = ext_gcd(b%a,a,&x1,&y1);*x=y1-(b/a)*x1;*y=x1;return gcd;}
//bool mark[mx];vector<ll>prime;
//void sieve(){memset(mark,true,sizeof(mark));for(ll i=3;i<=(ll)sqrt(mx);i+=2){if(mark[i]){for(ll j=i*i;j<=mx;j+=2*i) mark[j]=false;}}prime.push_back(2);for(ll i=3;i<=mx;i+=2) if(mark[i]) prime.push_back(i);}

template <typename T> T gcd(T a, T b){while (b){T t = a % b;a = b;b = t;}return a;}
template <typename T> T lcm(T a, T b){return a / gcd(a, b) * b;}
template <typename T> T gcd(T a, T b, T c){return gcd(gcd(a, b), c);}
template <typename T> bool isPrime(T x){if (x<=4||x%2==0||x%3==0)return x == 2 || x == 3;for (T i = 5; i * i <= x; i += 6) if (x % i == 0 || x % (i + 2) == 0) return 0;return 1;}

template <typename T> bool bitcheck(T p,T pos){return (bool)(p&(1<<pos));}
template <typename T> T biton(T p,T pos){return p=p|(1<<pos);}
template <typename T> T bitoff(T p,T pos){return p=p&~(1<<pos);}
template <typename T> ll toint(T s) {ll p;stringstream ss(s); ss>>p; return p;}
template <typename T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
template <typename T> T POW(T b,T p) {T Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
template <typename T> T BigMod(T b,T p,T Mod) {T Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
template <typename T> T ModInverse(T p,T Mod) {return BigMod(p,Mod-2,Mod);}
//template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//template <typename T> using ordered_set2 = tree<pair <T, string>, null_type, less<pair <T, string>>, rb_tree_tag, tree_order_statistics_node_update>;
ll histogram(ll arr[],ll n){ll top,i=0,sum=0,max_area=0;stack<ll>st;st.push(0);while(i<n){if(st.empty()||arr[st.top()]<=arr[i]) st.push(i++);else{top=st.top();st.pop();if(st.empty())sum=arr[top]*i;else sum=arr[top]*(i-st.top()-1);max_area=max(sum,max_area);}}while(!st.empty()){top=st.top();st.pop();if(st.empty()) sum=arr[top]*i;else sum=arr[top]*(i-st.top()-1);max_area=max(sum,max_area);}return max_area;}

#define mx              100010
#define inf             0x3f3f3f3f
#define mod             1000000007
#define PI              2*acos(0.0)
#define E               2.71828182845904523536

struct data{
    pii a,b,c;
};
int n;
string graph[15];
map<pii,int>mp;

int vis[10][10][10][10][10][10],dis[10][10][10][10][10][10];

int check(pii a2){
    //deb(a2.F,a2.S);
    if(valid(a2.F,a2.S)&&graph[a2.F][a2.S]!='#') return 1;
    return 0;
}
int bfs(data ob){
    queue<data>q;
    vis[ob.a.F][ob.a.S][ob.b.F][ob.b.S][ob.c.F][ob.c.S]=1;
    dis[ob.a.F][ob.a.S][ob.b.F][ob.b.S][ob.c.F][ob.c.S]=0;
    q.push(ob);
    while(!q.empty()){
        data u=q.front();q.pop();
        if(mp[u.a]==1&&mp[u.b]==1&&mp[u.c]==1&&u.a!=u.b&&u.b!=u.c&&u.a!=u.c)
            return dis[u.a.F][u.a.S][u.b.F][u.b.S][u.c.F][u.c.S];
        loop(i,4){
            data v;
            pii a2=pii(u.a.F+fx[i],u.a.S+fy[i]);
            pii b2=pii(u.b.F+fx[i],u.b.S+fy[i]);
            pii c2=pii(u.c.F+fx[i],u.c.S+fy[i]);
            if(!check(a2)) a2=u.a;
            if(!check(b2)) b2=u.b;
            if(!check(c2)) c2=u.c;
            if(a2==b2){
                a2=u.a;b2=u.b;
                if(a2==c2) c2=u.c;
            }
            if(a2==c2){
                a2=u.a;c2=u.c;
//                if(a2==b2) b2=u.b;
            }
            if(b2==c2){
                b2=u.b;c2=u.c;
                if(b2==a2) a2=u.a;
            }

            v.a=a2;v.b=b2;v.c=c2;
            if(vis[v.a.F][v.a.S][v.b.F][v.b.S][v.c.F][v.c.S]==0){
                vis[v.a.F][v.a.S][v.b.F][v.b.S][v.c.F][v.c.S]=1;
                dis[v.a.F][v.a.S][v.b.F][v.b.S][v.c.F][v.c.S]=dis[u.a.F][u.a.S][u.b.F][u.b.S][u.c.F][u.c.S]+1;
                q.push(v);
            }
        }
    }
    return -1;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    //fast;
    int t;
    scanf("%d",&t);
    loop1(cs,t){
        for(int i=0;i<15;i++) graph[i].clear();
        mp.clear();
        mem(vis,0);
        mem(dis,0);
        cin>>n;
        for(int i=0;i<n;i++) cin>>graph[i];
        data ob;
        loop(i,n) loop(j,n){
            if(graph[i][j]=='X') mp[pii(i,j)]=1;
            if(graph[i][j]=='A') ob.a=pii(i,j);
            if(graph[i][j]=='B') ob.b=pii(i,j);
            if(graph[i][j]=='C') ob.c=pii(i,j);
        }
//        deb(ob.a.F,ob.a.S);
        int ans=bfs(ob);
        case_print;
        if(ans==-1) cout<<"trapped\n";
        else cout<<ans<<endl;
    }
    return 0;
}
/*
3

7

.....#.

.......

.#B....

...A.#.

.CX....

.X.X.#.

.#.....

3

ABC

...

XXX

3

ABC

###

XXX
*/
