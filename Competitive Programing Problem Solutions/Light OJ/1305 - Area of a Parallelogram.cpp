#include<bits/stdc++.h>
//#define mx             100010
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define ll             long long int
//#define pp             pair<int,int>
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//int biton(int p,int pos){return p=p|(1<<pos);}
//int bitoff(int p,int pos){return p=p&~(1<<pos);}
//bool bitcheck(int p,int pos){return (bool)(p&(1<<pos));}
//ll POW(ll b,ll p) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
//ll BigMod(ll b,ll p,ll Mod) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
//ll ModInverse(ll p,ll Mod) {return BigMod(p,Mod-2,Mod);}
using namespace std;

int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        double ax,ay,bx,by,cx,cy;
        scanf("%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&cx,&cy);
        double dx=ax+cx-bx;
        double dy=ay+cy-by;
        double area=.5*(ax*by+bx*cy+cx*dy+dx*ay-bx*ay-cx*by-dx*cy-ax*dy);
        if(area<0) area*=(-1);
        printf("Case %d: %.0f %.0f %.0f\n",cs,dx,dy,area);
    }
    return 0;
}
/**
Input:

Output:

Formula
Shoelace Formula: Given the coordinates of vertices of a polygon, its area is found by
A=12∣∣∣∑i=1n−1xiyi+1+xny1−∑i=1n−1xi+1yi−x1yn∣∣∣
Or, in other words, we have
A=12|x1y2+x2y3+…xn−1yn+xny1−x2y1−x3y2−…−xnyn−1−x1yn|
Where A is the area of the polygon, and (xi,yi) with i=1,2,3… are the vertices of the polyon
**/
