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
#define loop(i,a,n)         for(int i=a;i<=n;i++)
#define loop1(i,n,a)        for(int i=n;i>=a;i--)

template <typename T> bool bitcheck(T p,T pos){return (bool)(p&(1<<pos));}
template <typename T> T biton(T p,T pos){return p=p|(1<<pos);}
template <typename T> T bitoff(T p,T pos){return p=p&~(1<<pos);}
template <typename T> ll toint(T s) {ll p;stringstream ss(s); ss>>p; return p;}
template <typename T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
template <typename T> T POW(T b,T p) {T Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
template <typename T> T BigMod(T b,T p,T Mod) {T Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
template <typename T> T ModInverse(T p,T Mod) {return BigMod(p,Mod-2,Mod);}
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ll ext_gcd(ll a,ll b,ll *x,ll *y){if(a==0){*x=0;*y=1;return b;}ll x1,y1;ll gcd = ext_gcd(b%a,a,&x1,&y1);*x=y1-(b/a)*x1;*y=x1;return gcd;}
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args> void deb(istream_iterator<string> it, T a, Args... args) {cerr << *it << " = " << a << endl;deb(++it, args...);}

const int fx[]      = {+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]      = {-1,+1,+0,+0,+1,+1,-1,-1};
const int mx        = 1e5+10;
const int inf       = 0x3f3f3f3f;
const int mod       = 1e9+7;
const double pi         = 2*acos(0.0);
const double E          = 2.71828182845904523536;
const double eps        = 1e-9;
bool mark[mx];vector<int>prime;
void sieve(){memset(mark,true,sizeof(mark));for(int i=3;i<=(int)sqrt(mx);i+=2){if(mark[i]){for(int j=i*i;j<=mx;j+=2*i) mark[j]=false;}}prime.push_back(2);for(int i=3;i<=mx;i+=2) if(mark[i]) prime.push_back(i);}
///Geometry
int EQ(double x){
    if(fabs(x)<eps) return 0;
    else if(x>0) return 1;
    else return -1;
}
struct PT{
    double x, y;
    PT() {}
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y) {}
    PT operator + (const PT &p) const{
        return PT(x+p.x, y+p.y);
    }
    PT operator - (const PT &p) const{
        return PT(x-p.x, y-p.y);
    }
    PT operator * (double c) const{
        return PT(x*c, y*c);
    }
    PT operator / (double c) const{
        return PT(x/c, y/c);
    }
};
double dot(PT p, PT q){
    return p.x*q.x+p.y*q.y;
}
double dist2D_sqr(PT p, PT q){
    return dot(p-q, p-q);
}
double dist2D(PT p, PT q){
    return sqrt(dot(p-q, p-q));
}
double cross(PT p, PT q){
    return p.x*q.y-p.y*q.x;
}
/// Rotates a point CCW or CW around the Origin
PT RotateCCW90(PT p){
    return PT(-p.y,p.x);
}
PT RotateCW90(PT p){
    return PT(p.y,-p.x);
}
PT RotateCCW(PT p, double theta){
    return PT(p.x*cos(theta)-p.y*sin(theta), p.x*sin(theta)+p.y*cos(theta));
}
PT RotateCW(PT p, double theta){
    return PT(p.x*cos(theta)+p.y*sin(theta), -p.x*sin(theta)+p.y*cos(theta));
}

/// Finds a point from 'a' through 'b' with distance 'd'
PT PointAlongLine(PT a, PT b, double d){
    return a+(((b-a)/sqrt(dot(b-a,b-a)))*d);
}

/// Projects the point 'c' onto line through 'a' and 'b' (assuming a != b)
PT ProjectPointToLine(PT a, PT b, PT c){
    return a+(b-a)*dot(c-a, b-a)/dot(b-a, b-a);
}

/// Projects point 'c' onto the line segment through 'a' and 'b'
PT ProjectPointToSegment(PT a, PT b, PT c){
    double r=dot(b-a,b-a);
    if(fabs(r)<eps) return a;
    r=dot(c-a, b-a)/r;
    if(r<0) return a;
    if(r>1) return b;
    return a+(b-a)*r;
}

/// Computes distance from 'c' to the line segment between 'a' and 'b'
double DistanceFromPointToSegment(PT a, PT b, PT c){
    return dist2D(c, ProjectPointToSegment(a, b, c));
}

/// Computes minimum distance from a point 'p' to a line 'AB'
double DistToLine(PT p, PT A, PT B){
    double scale=dot(p-A,B-A)/dot(B-A,B-A);
    PT c;
    c.x=A.x+scale*(B.x-A.x);
    c.y=A.y+scale*(B.y-A.y);
    return dist2D(p, c);
}

/// Computes minimum distance from a point 'p' to a line segment 'AB'
double DistToLineSegment(PT p, PT A, PT B){
    PT c;
    if(dot(B-A,p-A)<eps) return dist2D(p, A);
    if(dot(A-B,p-B)<eps) return dist2D(p, B);
    return DistToLine(p, A, B);
}

/// Checks whether a point 'p' is on the line segment between 'a' and 'b' or not
//bool PointOnSegment(PT p, PT a, PT b)
//{
//    if(fabs(cross(p-b,a-b))<eps){
//        if(p.x<min(a.x,b.x)||p.x>max(a.x,b.x)) return false;
//        if(p.y<min(a.y,b.y)||p.y>max(a.y,b.y)) return false;
//        return true;
//    }
//    return false;
//}
bool PointOnSegment(PT p, PT a, PT b)
{
    if((dist2D(p,a)+dist2D(p,b))>dist2D(a,b)+eps){

//        if(p.x<min(a.x,b.x)||p.x>max(a.x,b.x)) return false;
//        if(p.y<min(a.y,b.y)||p.y>max(a.y,b.y)) return false;
        return false;
    }
    return true;
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
    double a1=a.y-b.y;
    double b1=b.x-a.x;
    double c1=cross(a, b);
    double a2=c.y-d.y;
    double b2=d.x-c.x;
    double c2=cross(c, d);
    double D=a1*b2-a2*b1;
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
vector<PT> CircleLineIntersection(PT a, PT b, PT c, double r){
    vector<PT>ret;
    b=b-a;
    a=a-c;
    double A=dot(b, b);
    double B=dot(a, b);
    double C=dot(a, a)-r*r;
    double D=B*B-A*C;
    if(D<-eps) return ret;
    ret.push_back(c+a+b*(-B+sqrt(D+eps))/A);
    if(D>eps) ret.push_back(c+a+b*(-B-sqrt(D))/A);
    return ret;
}

/// Computes intersection of the circle centered at 'c1' with radius 'r1' with the circle centered at 'c2' with radius 'r2'
vector<PT> CircleCircleIntersection(PT c1, PT c2, double r1, double r2){
    vector<PT>ret;
    double d=dist2D(c1, c2);
    if(d>r1+r2 || d+min(r1, r2)<max(r1, r2)) return ret;
    double x=(d*d-r2*r2+r1*r1)/(2.0*d);
    double y=sqrt(r1*r1-x*x);
    PT v=(c2-c1)/d;
    ret.push_back(c1+v*x+RotateCCW90(v)*y);
    if(y>0) ret.push_back(c1+v*x-RotateCCW90(v)*y);
    return ret;
}

/// Computes the area of a possibly non-convex polygon, assuming that the coordinates are listed in a clockwise or counterclockwise fashion
double ComputeSignedArea(const vector<PT>p){
    double area=0.0;
    for(int i=0; i<p.size(); i++){
        int j=(i+1)%p.size();
        area+=p[i].x*p[j].y-p[j].x*p[i].y;
    }
    return area/2.0;
}

double ComputeArea(const vector<PT>p){
    return fabs(ComputeSignedArea(p));
}

/// Computes the centroid of a possibly non-convex polygon, assuming that the coordinates are listed in a clockwise or counterclockwise fashion
PT ComputeCentroid(const vector<PT>p){
    PT c=PT(0.0,0.0);
    double scale=6.0*ComputeSignedArea(p);
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
pair<PT,PT> GetParallelLine(PT a, PT b, double d){
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
        double c1=cross(ln.second-ln.first, poly[i]-ln.first);
        double c2=cross(ln.second-ln.first, poly[(i+1)%s]-ln.first);
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
double DistancePointPlane(double x, double y, double z, double a, double b, double c, double d){
    return fabs(a*x+b*y+c*z-d)/sqrt(a*a+b*b+c*c);
}
///Computes ARC a circle given by two points and radius
double cal_arc_(PT p1,PT p2,double r){
    double A = dist2D_sqr(p1,p2);
    double B = dist2D_sqr(p1,PT(0.0,0.0));
    double C = dist2D_sqr(p2,PT(0.0,0.0));
    double ang = acos((B+C-A)/(2.0*sqrt(B*C)));
    return r*ang;
}
double cal_ang(double A,double B,double C){
    double ang = acos(((B*B)+(C*C)-(A*A))/(2.0*(B*C)));
    return ang;
}
///code start here


int main(){
    freopen("angle2.in","r",stdin);
    freopen("angle2.out","w",stdout);
    double x,y,x2,y2;
    scanf("%lf%lf",&x,&y);
    scanf("%lf%lf",&x2,&y2);
//    double d=sqrt(x*x+y*y);
//    double d2=sqrt(x2*x2+y2*y2);
//    double d3=x*x2+y*y2;
//    double ang=acos(d3/(d*d2));
    double ang=atan2(cross(PT(x,y),PT(x2,y2)),dot(PT(x,y),PT(x2,y2)));
//        double dd=ang*(180/pi);

//    debug(dd);
    ang=abs(ang);
    ang=min(ang,2*pi-ang);
//    if(ang<0){
//        ang+=2.0*pi;
//    }
//    dd=ang*(180/pi);
//    debug(dd);

    pf("%.10f\n",ang);
    return 0;
}
/*

*/

