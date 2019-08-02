#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vs vector<string>
#define vpll vector<pll>
#define vpii vector<pii>
#define umap unordered_map
#define uset unordered_set
#define PQ priority_queue

#define printa(a,L,R) for(int i=L;i<R;i++) cout<<a[i]<<(i==R-1?'\n':' ')
#define printv(a) printa(a,0,a.size())
#define print2d(a,r,c) for(int i=0;i<r;i++) for(int j=0;j<c;j++) cout<<a[i][j]<<(j==c-1?'\n':' ')
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define fbo find_by_order
#define ook order_of_key
#define MP make_pair
#define UB upper_bound
#define LB lower_bound
#define SQ(x) ((x)*(x))
#define issq(x) (((ll)(sqrt((x))))*((ll)(sqrt((x))))==(x))
#define F first
#define S second
#define mem(a,x) memset(a,x,sizeof(a))
#define PI (acos(-1.0))
#define E 2.71828182845904523536
#define gamma 0.5772156649
#define nl "\n"
#define lg(r,n) (int)(log2(n)/log2(r))
#define pf printf
#define sf scanf
#define _ccase printf("Case %lld: ",++cs)
#define _case cout<<"Case "<<++cs<<": "
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; }

#define asche cerr<<"Ekhane asche\n";
#define rev(v) reverse(v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())
#define grtsrt(v) sort(v.begin(),v.end(),greater<int>())
#define all(v) v.begin(),v.end()
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
#define toint(a) atoi(a.c_str())
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL)
#define valid(tx,ty) (tx>=0&&tx<n&&ty>=0&&ty<m)
#define one(x) __builtin_popcount(x)
#define Unique(v) v.erase(unique(all(v)),v.end())
#define stree ll l=(n<<1),r=l+1,mid=b+(e-b)/2
string tostr(int n) {stringstream rr;rr<<n;return rr.str();}
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//ll dx[]={1,0,-1,0,1,-1,-1,1};
//ll dy[]={0,1,0,-1,1,1,-1,-1};

#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args>
void deb(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    deb(++it, args...);
}

const int mod=1e9+7;
const int mxn=1e5+9;
const ld eps=1e-9;
//ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
//ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
//ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}
const double pi=acos(-1.0);
const double inf=1e20;
const int maxp=1111;
int dblcmp(double d)
{
    if (fabs(d)<eps)return 0;
    return d>eps?1:-1;
}
#define mp make_pair



struct point{
    double x, y;
    point() {}
    point(double x, double y) : x(x), y(y) {}
    point(const point &p) : x(p.x), y(p.y) {}
    void input()        {   scanf("%lf%lf",&x,&y);}
    point operator + (const point &p) const{
        return point(x+p.x, y+p.y);
    }
    point operator - (const point &p) const{
        return point(x-p.x, y-p.y);
    }
    point operator * (double c) const{
        return point(x*c, y*c);
    }
    point operator / (double c) const{
        return point(x/c, y/c);
    }
    double val(){
        return sqrt(x*x+y*y);
    }
};
double dot(point p, point q){
    return p.x*q.x+p.y*q.y;
}
double dist2D_sqr(point p, point q){
    return dot(p-q, p-q);
}
double dist2D(point p, point q){
    return sqrt(dot(p-q, p-q));
}
double cross(point p, point q){
    return p.x*q.y-p.y*q.x;
}
double sq(point p){
    return (p.x*p.x+p.y*p.y);
}
double absolute(point p){
    return sqrt((double)sq(p));
}
point RotateCCW90(point p){
    return point(-p.y,p.x);
}
point RotateCW90(point p){
    return point(p.y,-p.x);
}
////////////////////////////////
struct line
{
    point v;
    double c;
    line(){}
    line(point _a,point _b): v(_b-_a),c(cross(v,_a)){};
    line(point _a,double _c):v(_a),c(_c){};
    line(double a,double b,double cc):v({b,-a}),c(cc){};
    line shift_l(double dis){
//        debug(c,dis,v.val());
        return {v,c+dis*v.val()};
    }
    double side(point p){
        return cross(v,p)-c;
    }
    double dis(point p){
//        debug(side(p),v.val());
        return fabs(side(p))/v.val();
    }
    bool cmpProj(point p, point q) {
        return dot(v,p) < dot(v,q);
    }

};
double orient(point a, point b, point c) {
    return cross(b-a,c-a);
}
bool inDisk(point a, point b, point p) {
    return dot(a-p, b-p) <= 0;
}
bool onSegment(point a, point b, point p) {
    return orient(a,b,p) == 0 && inDisk(a,b,p);
}
bool inter(line l1, line l2, point &out) {
    double d = cross(l1.v, l2.v);
//    debug(d);
    if (d == 0) return false;
    out = (l2.v*l1.c - l1.v*l2.c) / d; // requires floating-point coordinates
    return true;
}
bool lol(point a,point b,point p){
    line L(a,b);
    bool x=L.cmpProj(p,a);
    bool y=L.cmpProj(p,b);
    bool f=L.dis(p)<=(1e-10);
//    debug(f);
    if(L.dis(p)<=(1e-12) && (x==false||y==false)){
        return true;
    }
    else return false;
}
double ami(point a,point b,point p){
    point d=a-p;
    double aa=d.val();
    line L(a,b);
    bool x=L.cmpProj(p,a);
    bool y=L.cmpProj(p,b);
    if(x==true && y==true) return aa;
    else return L.dis(p);
}
int main(){
    freopen("raydist.in","r",stdin);
    freopen("raydist.out","w",stdout);

//    double a,b,c;

    point p,q,a,b;
//    p.input();
    p.input();
    q.input();
    a.input();
    b.input();
    line l1(p,q);
    line l2(a,b);
    point d;
//    debug(d.x,d.y);
    bool f=inter(l1,l2,d);
    bool x=lol(p,q,d);
    bool y=lol(a,b,d);

//    debug(f,x,y,d.x,d.y);
    cout<<fixed<<setprecision(5);
    if(f==true && x==true && y==true){
        cout<<0<<nl;
    }
    else{
        double ans=min(ami(p,q,a),ami(a,b,p));
        cout<<ans<<nl;
    }
//    cin>>a>>b>>c;
//    sf("%lf%lf",&c.x,&c.y);
//    line l1(a,b,-c);
//    line k=l1.shift_l(r);
//    debug(k.c);
//    if(k.c==0.000000000) pf("%.10f %.10f %.10f\n",-k.v.y,k.v.x,k.c);
//    else pf("%.10f %.10f %.10f\n",-k.v.y,k.v.x,-k.c);
//
//    k=l1.shift_l(-r);
//    debug(k.c);
//    debug(l1.dis(p));
//    bool ami=l1.cmpProj(p,a);
//    bool tumi=l1.cmpProj(p,b);

//    if(l1.side(p)*l1.side(q)>0)cout<<"YES"<<nl;
//    if(onSegment(a,b,p))cout<<"YES"<<nl;
//    else if(ami==false || tumi==false) cout<<"YES"<<nl;
//    else cout<<<<nl;
//    pf("%.10f %.10f %.10f\n",-k.v.y,k.v.x,-k.c);

    return 0;
}
/*

*/






