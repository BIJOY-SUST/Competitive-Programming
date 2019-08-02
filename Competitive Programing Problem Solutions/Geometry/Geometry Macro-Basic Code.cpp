#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#define _CRT_SECURE_NO_WARNINGS

# include <bits/stdc++.h>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cctype>
# include <stack>
# include <queue>
# include <vector>
# include <string>
# include <map>
# include <set>
# include <iostream>
# include <algorithm>
# include <sstream>
# include <cstdlib>
# include <complex>
# include <iomanip>
# include <utility>
# include <bitset>
# include <list>
# include <assert.h>
# include <numeric>
# include <fstream>
//#include <ext/pb_ds/detail/standard_policies.hpp>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;

#define F               first
#define S               second
#define pb              push_back
#define pp              pop_back()
#define UB              upper_bound
#define LB              lower_bound
#define ui              unsigned int
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
#define vpll            vector<pll>
#define sti             stack<int>
#define stll            stack<ll>
#define qi              queue<int>
#define qll             queue<ll>
#define sei             set<int>
#define sell            set<ll>
#define sec             set<char>
#define ses             set<string>
#define pqi             priority_queue<int>
#define pqgrt           priority_queue<int,vector<int>,greater<int> >
#define mpii            map<int,int>
#define mpll            map<ll,ll>
#define mpsi            map<string,int>
#define mpis            map<int,string>
#define mpci            map<char,int>
#define umpii           unordered_map<int,int>
#define umpll           unordered_map<ll,ll>
#define umpsi           unordered_map<string,int>
#define umpis           unordered_map<int,string>
#define umpci           unordered_map<char,int>
#define ump             unordered_map
#define use             unordered_set
#define pq              priority_queue

#define nl                  '\n'
#define pf                  printf
#define sfc(a)              scanf("%c",&a)
#define sfs(a)              scanf("%s",&a)
#define sfi1(a)             scanf("%d",&a)
#define sfi2(a,b)           scanf("%d %d",&a,&b)
#define sfi3(a,b,c)         scanf("%d %d %d",&a,&b,&c)
#define sfi4(a,b,c,d)       scanf("%d %d %d %d",&a,&b,&c,&d)
#define sfd1(a)             scanf("%lf",&a)
#define sfd2(a,b)           scanf("%lf %lf",&a,&b)
#define sfd3(a,b,c)         scanf("%lf %lf %lf",&a,&b,&c)
#define sfd4(a,b,c,d)       scanf("%lf %lf %lf %lf",&a,&b,&c,&d)
#define sfll1(a)            scanf("%lld",&a)
#define sfll2(a,b)          scanf("%lld %lld",&a,&b)
#define sfll3(a,b,c)        scanf("%lld %lld %lld",&a,&b,&c)
#define sfll4(a,b,c,d)      scanf("%lld %lld %lld %lld",&a,&b,&c,&d)
#define sfull1(a)           scanf("%llu",&a)
#define sfull2(a,b)         scanf("%llu %llu",&a,&b)
#define sfull3(a,b,c)       scanf("%llu %llu %llu",&a,&b,&c)
#define sfull4(a,b,c,d)     scanf("%llu %llu %llu %llu",&a,&b,&c,&d)

#define sqr(a)              ((a)*(a))
#define ang(a, b, c)        acos((sqr(b)+sqr(c)-sqr(a))/(2.0*b*c))
#define dist(x1,y1,x2,y2)   sqrt(sqr(x1-x2)+sqr(y1-y2))
#define rev(v)              reverse(v.begin(),v.end())
#define srt(v)              sort(v.begin(),v.end())
#define grtsrt(v)           sort(v.begin(),v.end(),greater<pll>())
#define all(v)              v.begin(),v.end()
#define minv(v)             *min_element(v.begin(),v.end())
#define maxv(v)             *max_element(v.begin(),v.end())
#define cntv(v,a)           count(v.begin(),v.end(),a)
#define one(x)              __builtin_popcount(x)
#define valid(tx,ty)        tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)        memset(arr,val,sizeof(arr))
#define Unique(x)           x.erase(unique(x.begin(),x.end()),x.end())
#define fast                ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define forstl(it,v)        for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define loop(i,n)           for(int i=0;i<n;i++)
#define loop1(i,n)          for(int i=1;i<=n;i++)
#define case_print          printf("Case %d: ",cs)

template <class T1> void deb(T1 e1){cout<<e1<<endl;}
template <class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template <class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template <class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template <class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template <class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}

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
//ll histogram(ll arr[],ll n){ll top,i=0,sum=0,max_area=0;stack<ll>st;st.push(0);while(i<n){if(st.empty()||arr[st.top()]<=arr[i]) st.push(i++);else{top=st.top();st.pop();if(st.empty())sum=arr[top]*i;else sum=arr[top]*(i-st.top()-1);max_area=max(sum,max_area);}}while(!st.empty()){top=st.top();st.pop();if(st.empty()) sum=arr[top]*i;else sum=arr[top]*(i-st.top()-1);max_area=max(sum,max_area);}return max_area;}
//ll ext_gcd(ll a,ll b,ll *x,ll *y){if(a==0){*x=0;*y=1;return b;}ll x1,y1;ll gcd = ext_gcd(b%a,a,&x1,&y1);*x=y1-(b/a)*x1;*y=x1;return gcd;}

const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
const int mx        = 1e5+10;
const int inf       = 0x3f3f3f3f;
const int mod       = 1e9+7;
const ld pi         = 2*acos(0.0);
const ld E          = 2.71828182845904523536;
const ld eps        = 1e-9;
//ll fact[mx];
//void factorial(){fact[0]=1;loop1(i,mx-1) fact[i]=(fact[i-1]*i)%mod;}
//ll nCr(ll n,ll r){return (fact[n]*ModInverse(((ll)fact[n-r]*(ll)fact[r])%mod,(ll)mod))%mod;}
//bool mark[mx];vector<ll>prime;
//void sieve(){memset(mark,true,sizeof(mark));for(ll i=3;i<=(ll)sqrt(mx);i+=2){if(mark[i]){for(ll j=i*i;j<=mx;j+=2*i) mark[j]=false;}}prime.push_back(2);for(ll i=3;i<=mx;i+=2) if(mark[i]) prime.push_back(i);}

///Geometry
int EQ(ld x){
    if(fabs(x)<eps) return 0;
    else if(x>0) return 1;
    else return -1;
}
struct PT{
    ld x, y;
    PT() {}
    PT(ld x, ld y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y) {}
    PT operator + (const PT &p) const{
        return PT(x+p.x, y+p.y);
    }
    PT operator - (const PT &p) const{
        return PT(x-p.x, y-p.y);
    }
    PT operator * (ld c) const{
        return PT(x*c, y*c);
    }
    PT operator / (ld c) const{
        return PT(x/c, y/c);
    }
};
ld dot(PT p, PT q){
    return p.x*q.x+p.y*q.y;
}
ld dist2D_sqr(PT p, PT q){
    return dot(p-q, p-q);
}
ld dist2D(PT p, PT q){
    return sqrt(dot(p-q, p-q));
}
ld cross(PT p, PT q){
    return p.x*q.y-p.y*q.x;
}
/// Rotates a point CCW or CW around the Origin
PT RotateCCW90(PT p){
    return PT(-p.y,p.x);
}
PT RotateCW90(PT p){
    return PT(p.y,-p.x);
}
PT RotateCCW(PT p, ld theta){
    return PT(p.x*cos(theta)-p.y*sin(theta), p.x*sin(theta)+p.y*cos(theta));
}
PT RotateCW(PT p, ld theta){
    return PT(p.x*cos(theta)+p.y*sin(theta), -p.x*sin(theta)+p.y*cos(theta));
}

/// Finds a point from 'a' through 'b' with distance 'd'
PT PointAlongLine(PT a, PT b, ld d){
    return a+(((b-a)/sqrt(dot(b-a,b-a)))*d);
}

/// Projects the point 'c' onto line through 'a' and 'b' (assuming a != b)
PT ProjectPointToLine(PT a, PT b, PT c){
    return a+(b-a)*dot(c-a, b-a)/dot(b-a, b-a);
}

/// Projects point 'c' onto the line segment through 'a' and 'b'
PT ProjectPointToSegment(PT a, PT b, PT c){
    ld r=dot(b-a,b-a);
    if(fabs(r)<eps) return a;
    r=dot(c-a, b-a)/r;
    if(r<0) return a;
    if(r>1) return b;
    return a+(b-a)*r;
}

/// Computes distance from 'c' to the line segment between 'a' and 'b'
ld DistanceFromPointToSegment(PT a, PT b, PT c){
    return dist2D(c, ProjectPointToSegment(a, b, c));
}

/// Computes minimum distance from a point 'p' to a line 'AB'
ld DistToLine(PT p, PT A, PT B){
    ld scale=dot(p-A,B-A)/dot(B-A,B-A);
    PT c;
    c.x=A.x+scale*(B.x-A.x);
    c.y=A.y+scale*(B.y-A.y);
    return dist2D(p, c);
}

/// Computes minimum distance from a point 'p' to a line segment 'AB'
ld DistToLineSegment(PT p, PT A, PT B){
    PT c;
    if(dot(B-A,p-A)<eps) return dist2D(p, A);
    if(dot(A-B,p-B)<eps) return dist2D(p, B);
    return DistToLine(p, A, B);
}

/// Checks whether a point 'p' is on the line segment between 'a' and 'b' or not
bool PointOnSegment(PT p, PT a, PT b)
{
    if(fabs(cross(p-b,a-b))<eps){
        if(p.x<min(a.x,b.x)||p.x>max(a.x,b.x)) return false;
        if(p.y<min(a.y,b.y)||p.y>max(a.y,b.y)) return false;
        return true;
    }
    return false;
}

/// Determines whether the lines from 'a' to 'b' and 'c' to 'd' are parallel or not
bool LinesParallel(PT a, PT b, PT c, PT d){
    return fabs(cross(b-a, c-d))<eps;
}

/// Determines if the lines from 'a' to 'b' and 'c' to 'd' are collinear or not
bool LinesCollinear(PT a, PT b, PT c, PT d){
    return LinesParallel(a, b, c, d) && fabs(cross(a-b, a-c))<eps && fabs(cross(c-d, c-a))<eps;
}

/// Before calling this, check whether the line segments are parallel or not
/// Determines whether the line segment between 'a' and 'b' intersects with the line segment between 'c' and 'd'
bool SegmentsIntersect(PT a, PT b, PT c, PT d){
    if(LinesCollinear(a, b, c, d)){
        if(dist2D_sqr(a, c)<eps || dist2D_sqr(a, d)<eps || dist2D_sqr(b, c)<eps || dist2D_sqr(b, d)<eps) return true;
        if(dot(c-a, c-b)>0 && dot(d-a, d-b)>0 && dot(c-b, d-b)>0) return false;
        return true;
    }
    if(cross(d-a, b-a)*cross(c-a, b-a)>0) return false;
    if(cross(a-c, d-c)*cross(b-c, d-c)>0) return false;
    return true;
}

/// Computes intersection of the line passing through 'a' and 'b' with the line passing through 'c' and 'd'
PT ComputeLineIntersection(PT a, PT b, PT c, PT d){
    ld a1=a.y-b.y;
    ld b1=b.x-a.x;
    ld c1=cross(a, b);
    ld a2=c.y-d.y;
    ld b2=d.x-c.x;
    ld c2=cross(c, d);
    ld D=a1*b2-a2*b1;
    return PT((b1*c2-b2*c1)/D, (c1*a2-c2*a1)/D);
}

/// Computes center of the circle passing through the points 'a', 'b' and 'c'
PT ComputeCircleCenter(PT a, PT b, PT c){
    b=(a+b)/2;
    c=(a+c)/2;
    return ComputeLineIntersection(b, b+RotateCW90(a-b), c, c+RotateCW90(a-c));
}

/// Determines whether a point 'q' is on the boundary of the polygon 'p' or not
bool PointOnBoundaryOfPolygon(const vector<PT>p, PT q){
    int s=p.size();
    for(int i=0, j=s-1; i<s; j=i++){
        if(PointOnSegment(q, p[j], p[i])) return true;
    }
    return false;
}

/// Determines whether a point 'q' is in a possibly non-convex polygon or not.
/// Returns '1' for strictly interior points, '0' for strictly exterior points, and '0' or '1' for the remaining points.
bool PointInPolygon(const vector<PT>p, PT q){
    bool c=0;
    int s=p.size();
    for(int i=0,j=s-1; i<s; j=i++){
        if(((p[i].y>q.y)!=(p[j].y>q.y))&&(q.x<p[i].x+(p[j].x-p[i].x)*(q.y-p[i].y)/(p[j].y-p[i].y))) c=!c;
    }
    return c;
}

/// Computes intersection of the line through points 'a' and 'b' with the circle centered at 'c' with radius 'r'
vector<PT> CircleLineIntersection(PT a, PT b, PT c, ld r){
    vector<PT>ret;
    b=b-a;
    a=a-c;
    ld A=dot(b, b);
    ld B=dot(a, b);
    ld C=dot(a, a)-r*r;
    ld D=B*B-A*C;
    if(D<-eps) return ret;
    ret.push_back(c+a+b*(-B+sqrt(D+eps))/A);
    if(D>eps) ret.push_back(c+a+b*(-B-sqrt(D))/A);
    return ret;
}

/// Computes intersection of the circle centered at 'c1' with radius 'r1' with the circle centered at 'c2' with radius 'r2'
vector<PT> CircleCircleIntersection(PT c1, PT c2, ld r1, ld r2){
    vector<PT>ret;
    ld d=dist2D(c1, c2);
    if(d>r1+r2 || d+min(r1, r2)<max(r1, r2)) return ret;
    ld x=(d*d-r2*r2+r1*r1)/(2.0*d);
    ld y=sqrt(r1*r1-x*x);
    PT v=(c2-c1)/d;
    ret.push_back(c1+v*x+RotateCCW90(v)*y);
    if(y>0) ret.push_back(c1+v*x-RotateCCW90(v)*y);
    return ret;
}

/// Computes the area of a possibly non-convex polygon, assuming that the coordinates are listed in a clockwise or counterclockwise fashion
ld ComputeSignedArea(const vector<PT>p){
    ld area=0.0;
    for(int i=0; i<p.size(); i++){
        int j=(i+1)%p.size();
        area+=p[i].x*p[j].y-p[j].x*p[i].y;
    }
    return area/2.0;
}

ld ComputeArea(const vector<PT>p){
    return fabs(ComputeSignedArea(p));
}

/// Computes the centroid of a possibly non-convex polygon, assuming that the coordinates are listed in a clockwise or counterclockwise fashion
PT ComputeCentroid(const vector<PT>p){
    PT c=PT(0.0,0.0);
    ld scale=6.0*ComputeSignedArea(p);
    for(int i=0; i<p.size(); i++){
        int j=(i+1)%p.size();
        c=c+(p[i]+p[j])*(p[i].x*p[j].y-p[j].x*p[i].y);
    }
    return c/scale;
}

/// Checks whether or not a the polygon 'p' (in CW or CCW order) is simple
bool IsSimple(const vector<PT>p){
    for(int i=0; i<p.size(); i++){
        for(int k=i+1; k<p.size(); k++){
            int j=(i+1)%p.size();
            int l=(k+1)%p.size();
            if(i==l || j==k) continue;
            if(SegmentsIntersect(p[i], p[j], p[k], p[l])) return false;
        }
    }
    return true;
}

/// Returns a parallel line of the line 'ab' in CCW direction with d distance from 'ab'
pair<PT,PT> GetParallelLine(PT a, PT b, ld d){
    return make_pair(PointAlongLine(a, RotateCCW90(b-a)+a, d), PointAlongLine(b, RotateCW90(a-b)+b, d));
}

/// Returns the perpendicular line of the line 'ab' which intersects with it at point 'c' in CCW direction
pair<PT,PT> GetPerpendicularLine(PT a, PT b, PT c){
    return make_pair(RotateCCW90(a-c)+c,RotateCCW90(b-c)+c);
}
vector<PT>HalfPlaneIntersection(vector<PT>poly, pair<PT,PT>ln){
    vector<PT>ret;
    int s=poly.size();
    for(int i=0; i<s; i++){
        ld c1=cross(ln.second-ln.first, poly[i]-ln.first);
        ld c2=cross(ln.second-ln.first, poly[(i+1)%s]-ln.first);
        if(EQ(c1)>=0) ret.push_back(poly[i]);
        if(EQ(c1*c2)<0){
            if(!LinesParallel(poly[i], poly[(i+1)%s], ln.first, ln.second)){
                ret.push_back(ComputeLineIntersection(poly[i], poly[(i+1)%s], ln.first, ln.second));
            }
        }
    }
    return ret;
}

/// Computes distance between a point (x,y,z) and a plane ax+by+cz=d
ld DistancePointPlane(ld x, ld y, ld z, ld a, ld b, ld c, ld d){
    return fabs(a*x+b*y+c*z-d)/sqrt(a*a+b*b+c*c);
}
///code start here


int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);

    return 0;
}
/*

*/
