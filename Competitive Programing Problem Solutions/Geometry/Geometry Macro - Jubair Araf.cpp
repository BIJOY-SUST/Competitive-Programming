///HEADER FILES///

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <complex>
#include <iomanip>
#include <utility>
#include <bitset>
#include <list>
#include <assert.h>
#include <numeric>
#include <fstream>
using namespace std;

///DEFINES///

///ALWAYS USEFUL
#define     caseprint(case)     printf("Case %d: ", case ++)
#define     caseprintnl(case)   printf("Case %d:\n", case ++)
#define     clr(a)              memset(a, 0, sizeof(a))
#define     mem(a, b)           memset(a, b, sizeof(a))
#define     pb                  push_back
#define     pp                  pop_back
#define     full(v)             v.begin(), v.end()
#define     sort_vec(v)         sort(full(v))
#define     sf                  scanf
#define     pf                  printf
#define     NL                  pf("\n")
#define     sz(a)               (int)a.size()
#define     bitcheck(n, pos)    (n & (1<<(pos)))
#define     biton(n, pos)       (n | (1<<(pos)))
#define     bitoff(n, pos)      (n & ~(1<<(pos)))
#define     sqr(a)              ((a)*(a))

///SCAN
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
#define     sfull4(a, b, c, d)  scanf("%llu %llu %llu %llu", &a, &b, &c, &d)

///GEOMETRY
#define     ang(a, b, c)            acos((sqr(b)+sqr(c)-sqr(a))/(2.0*b*c))
#define     dist(x1, y1, x2, y2)    sqrt(sqr(x1-x2)+sqr(y1-y2))

///TYPES///
typedef     long long ll;
typedef     unsigned long long ull;
typedef     pair<int, int>      pii;
typedef     pair<ll, ll>        pll;

struct debugger
{
    template<typename T> debugger& operator, (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;
#define deb(args ...){dbg, args; cerr<<endl;}

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll BigMod(ll b, ll p, ll m) {if(!p) return 1; ll x=BigMod(b,p/2,m); x=(x*x)%m; if(p&1) x=(x*b)%m; return x;}
//ll bigmod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} ret urn R;} /// (B^P)%M

//int x[] = {0,0,-1,1};//4-ways
//int y[] = {1,-1,0,0};//4-ways
//int x[] = {-1,-1,-1,0,0,1,1,1};//8-ways
//int y[] = {-1,0,1,-1,1,-1,0,1};//8-ways
//int x[] = {-2,-2,2,2,1,1,-1,-1};//knight moves
//int y[] = {1,-1,1,-1,2,-2,2,-2};//knight moves

///CONSTANTS
#define     pi                  acos(-1.0)
#define     ex                  exp(1)

///OTHERS
#define     READ                freopen("input.txt","r",stdin);
#define     WRITE               freopen("out.txt","w",stdout);
#define     accelerate          ios_base::sync_with_stdio(false); cin.tie(NULL)
#define     debug               printf("Ok\n")
#define     MOD                 1000000007
#define     M                   500000

const double INF = 1e100;
const double EPS = 1e-9;

int EQ(double x)
{
    if(fabs(x)<EPS) return 0;
    else if(x>0) return 1;
    else return -1;
}

struct PT
{
    double x, y;
    PT() {}
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y) {}
    PT operator + (const PT &p) const
    {
        return PT(x+p.x, y+p.y);
    }
    PT operator - (const PT &p) const
    {
        return PT(x-p.x, y-p.y);
    }
    PT operator * (double c) const
    {
        return PT(x*c, y*c);
    }
    PT operator / (double c) const
    {
        return PT(x/c, y/c);
    }
};

double dot(PT p, PT q)
{
    return p.x*q.x+p.y*q.y;
}
double dist2D_sqr(PT p, PT q)
{
    return dot(p-q, p-q);
}
double dist2D(PT p, PT q)
{
    return sqrt(dot(p-q, p-q));
}
double cross(PT p, PT q)
{
    return p.x*q.y-p.y*q.x;
}

/// Rotates a point CCW or CW around the Origin

PT RotateCCW90(PT p)
{
    return PT(-p.y,p.x);
}

PT RotateCW90(PT p)
{
    return PT(p.y,-p.x);
}

PT RotateCCW(PT p, double theta)
{
    return PT(p.x*cos(theta)-p.y*sin(theta), p.x*sin(theta)+p.y*cos(theta));
}
PT RotateCW(PT p, double theta)
{
    return PT(p.x*cos(theta)+p.y*sin(theta), -p.x*sin(theta)+p.y*cos(theta));
}

/// Finds a point from 'a' through 'b' with distance 'd'

PT PointAlongLine(PT a, PT b, double d)
{
    return a+(((b-a)/sqrt(dot(b-a,b-a)))*d);
}

/// Projects the point 'c' onto line through 'a' and 'b' (assuming a != b)

PT ProjectPointToLine(PT a, PT b, PT c)
{
    return a+(b-a)*dot(c-a, b-a)/dot(b-a, b-a);
}

/// Projects point 'c' onto the line segment through 'a' and 'b'

PT ProjectPointToSegment(PT a, PT b, PT c)
{
    double r=dot(b-a,b-a);

    if(fabs(r)<EPS) return a;

    r=dot(c-a, b-a)/r;

    if(r<0) return a;
    if(r>1) return b;

    return a+(b-a)*r;
}

/// Computes distance from 'c' to the line segment between 'a' and 'b'

double DistanceFromPointToSegment(PT a, PT b, PT c)
{
    return dist2D(c, ProjectPointToSegment(a, b, c));
}

/// Computes minimum distance from a point 'p' to a line 'AB'

double DistToLine(PT p, PT A, PT B)
{
    double scale=dot(p-A,B-A)/dot(B-A,B-A);

    PT c;
    c.x=A.x+scale*(B.x-A.x);
    c.y=A.y+scale*(B.y-A.y);

    return dist2D(p, c);
}

/// Computes minimum distance from a point 'p' to a line segment 'AB'

double DistToLineSegment(PT p, PT A, PT B)
{
    PT c;
    if(dot(B-A,p-A)<EPS) return dist2D(p, A);
    if(dot(A-B,p-B)<EPS) return dist2D(p, B);

    return DistToLine(p, A, B);
}

/// Checks whether a point 'p' is on the line segment between 'a' and 'b' or not

bool PointOnSegment(PT p, PT a, PT b)
{
    if(fabs(cross(p-b,a-b))<EPS)
    {
        if(p.x<min(a.x,b.x)||p.x>max(a.x,b.x)) return false;
        if(p.y<min(a.y,b.y)||p.y>max(a.y,b.y)) return false;
        return true;
    }

    return false;
}

/// Determines whether the lines from 'a' to 'b' and 'c' to 'd' are parallel or not

bool LinesParallel(PT a, PT b, PT c, PT d)
{
    return fabs(cross(b-a, c-d))<EPS;
}

/// Determines if the lines from 'a' to 'b' and 'c' to 'd' are collinear or not

bool LinesCollinear(PT a, PT b, PT c, PT d)
{
    return LinesParallel(a, b, c, d) && fabs(cross(a-b, a-c))<EPS && fabs(cross(c-d, c-a))<EPS;
}

/// Before calling this, check whether the line segments are parallel or not
/// Determines whether the line segment between 'a' and 'b' intersects with the line segment between 'c' and 'd'

bool SegmentsIntersect(PT a, PT b, PT c, PT d)
{
    if(LinesCollinear(a, b, c, d))
    {
        if(dist2D_sqr(a, c)<EPS || dist2D_sqr(a, d)<EPS || dist2D_sqr(b, c)<EPS || dist2D_sqr(b, d)<EPS) return true;
        if(dot(c-a, c-b)>0 && dot(d-a, d-b)>0 && dot(c-b, d-b)>0) return false;
        return true;
    }

    if(cross(d-a, b-a)*cross(c-a, b-a)>0) return false;
    if(cross(a-c, d-c)*cross(b-c, d-c)>0) return false;

    return true;
}

/// Computes intersection of the line passing through 'a' and 'b' with the line passing through 'c' and 'd'

PT ComputeLineIntersection(PT a, PT b, PT c, PT d)
{
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

PT ComputeCircleCenter(PT a, PT b, PT c)
{
    b=(a+b)/2;
    c=(a+c)/2;
    return ComputeLineIntersection(b, b+RotateCW90(a-b), c, c+RotateCW90(a-c));
}

/// Determines whether a point 'q' is on the boundary of the polygon 'p' or not

bool PointOnBoundaryOfPolygon(const vector<PT>p, PT q)
{
    int s=p.size();
    for(int i=0, j=s-1; i<s; j=i++)
    {
        if(PointOnSegment(q, p[j], p[i])) return true;
    }

    return false;
}


/// Determines whether a point 'q' is in a possibly non-convex polygon or not.
/// Returns '1' for strictly interior points, '0' for strictly exterior points, and '0' or '1' for the remaining points.

bool PointInPolygon(const vector<PT>p, PT q)
{
    bool c=0;
    int s=p.size();

    for(int i=0,j=s-1; i<s; j=i++)
    {
        if(((p[i].y>q.y)!=(p[j].y>q.y))&&(q.x<p[i].x+(p[j].x-p[i].x)*(q.y-p[i].y)/(p[j].y-p[i].y))) c=!c;
    }

    return c;
}

/// Computes intersection of the line through points 'a' and 'b' with the circle centered at 'c' with radius 'r'

vector<PT> CircleLineIntersection(PT a, PT b, PT c, double r)
{
    vector<PT>ret;
    b=b-a;
    a=a-c;

    double A=dot(b, b);
    double B=dot(a, b);
    double C=dot(a, a)-r*r;
    double D=B*B-A*C;

    if(D<-EPS) return ret;

    ret.push_back(c+a+b*(-B+sqrt(D+EPS))/A);

    if(D>EPS) ret.push_back(c+a+b*(-B-sqrt(D))/A);

    return ret;
}

/// Computes intersection of the circle centered at 'c1' with radius 'r1' with the circle centered at 'c2' with radius 'r2'

vector<PT> CircleCircleIntersection(PT c1, PT c2, double r1, double r2)
{
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

double ComputeSignedArea(const vector<PT>p)
{
    double area=0.0;
    for(int i=0; i<p.size(); i++)
    {
        int j=(i+1)%p.size();
        area+=p[i].x*p[j].y-p[j].x*p[i].y;
    }

    return area/2.0;
}

double ComputeArea(const vector<PT>p)
{
    return fabs(ComputeSignedArea(p));
}

/// Computes the centroid of a possibly non-convex polygon, assuming that the coordinates are listed in a clockwise or counterclockwise fashion

PT ComputeCentroid(const vector<PT>p)
{
    PT c=PT(0.0,0.0);
    double scale=6.0*ComputeSignedArea(p);

    for(int i=0; i<p.size(); i++)
    {
        int j=(i+1)%p.size();
        c=c+(p[i]+p[j])*(p[i].x*p[j].y-p[j].x*p[i].y);
    }

    return c/scale;
}

/// Checks whether or not a the polygon 'p' (in CW or CCW order) is simple

bool IsSimple(const vector<PT>p)
{
    for(int i=0; i<p.size(); i++)
    {
        for(int k=i+1; k<p.size(); k++)
        {
            int j=(i+1)%p.size();
            int l=(k+1)%p.size();

            if(i==l || j==k) continue;

            if(SegmentsIntersect(p[i], p[j], p[k], p[l])) return false;
        }
    }

    return true;
}


/// Returns a parallel line of the line 'ab' in CCW direction with d distance from 'ab'

pair<PT,PT> GetParallelLine(PT a, PT b, double d)
{
    return make_pair(PointAlongLine(a, RotateCCW90(b-a)+a, d), PointAlongLine(b, RotateCW90(a-b)+b, d));
}

/// Returns the perpendicular line of the line 'ab' which intersects with it at point 'c' in CCW direction

pair<PT,PT> GetPerpendicularLine(PT a, PT b, PT c)
{
    return make_pair(RotateCCW90(a-c)+c,RotateCCW90(b-c)+c);
}

vector<PT>HalfPlaneIntersection(vector<PT>poly, pair<PT,PT>ln)
{
    vector<PT>ret;
    int s=poly.size();
    for(int i=0; i<s; i++)
    {
        double c1=cross(ln.second-ln.first, poly[i]-ln.first);
        double c2=cross(ln.second-ln.first, poly[(i+1)%s]-ln.first);

        if(EQ(c1)>=0) ret.push_back(poly[i]);
        if(EQ(c1*c2)<0)
        {
            if(!LinesParallel(poly[i], poly[(i+1)%s], ln.first, ln.second))
            {
                ret.push_back(ComputeLineIntersection(poly[i], poly[(i+1)%s], ln.first, ln.second));
            }
        }
    }

    return ret;
}


/// Computes distance between a point (x,y,z) and a plane ax+by+cz=d

double DistancePointPlane(double x, double y, double z, double a, double b, double c, double d)
{
    return fabs(a*x+b*y+c*z-d)/sqrt(a*a+b*b+c*c);
}


int main()
{

    return 0;
}
