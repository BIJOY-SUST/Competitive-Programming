#include<bits/stdc++.h>
//#define mx             100010
//#define mod            1000000007
#define pi             2*acos(0.0)
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
double dis(double x1,double y1,double x2,double y2){
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        double x1,y1,x2,y2,x3,y3,x4,y4;
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
        double a=dis(x1,y1,x2,y2);
        double b=dis(x2,y2,x3,y3);
        double c=dis(x3,y3,x4,y4);
        double d=dis(x4,y4,x1,y1);
        double ac=dis(x4,y4,x2,y2);
        double bd=dis(x1,y1,x3,y3);
//        double angle_da=(180.0/(1.0*pi))*acos((a*a+d*d-ac*ac)/(2.0*a*d));
//        double angle_ab=(180.0/(1.0*pi))*acos((a*a+b*b-bd*bd)/(2.0*a*b));
//        double angle_bc=(180.0/(1.0*pi))*acos((b*b+c*c-ac*ac)/(2.0*b*c));
//        double angle_cd=(180.0/(1.0*pi))*acos((c*c+d*d-bd*bd)/(2.0*c*d));
//        cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
//        cout<<setprecision(5)<<angle_da<<" "<<angle_ab<<" "<<angle_bc<<" "<<angle_cd<<endl;
        if(a==b&&b==c&&c==d){
            printf("Case %d: Square\n",cs);
        }
    }
    return 0;
}
/**
Input:
6
0 0
2 0
2 2
0 2
0 0
3 0
3 2
0 2
0 0
8 4
5 0
3 4
0 0
2 0
3 2
1 2
0 0
5 0
4 3
1 3
0 0
5 0
4 3
1 4
Output:
Case 1: Square
Case 2: Rectangle
Case 3: Rhombus
Case 4: Parallelogram
Case 5: Trapezium
Case 6: Ordinary Quadrilateral
**/
