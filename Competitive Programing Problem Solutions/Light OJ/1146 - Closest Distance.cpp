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
double ax,ay,bx,by,cx,cy,dx,dy;
double find_dis(double x1,double y1,double x2,double y2){
    return sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
}
double ternary_search(){
    double l = find_dis(ax,ay,cx,cy);
    double r = find_dis(bx,by,dx,dy);
    while(abs(r-l)>(1e-8)){
        double x1=ax+(bx-ax)/3.0;
        double y1=ay+(by-ay)/3.0;
        double x2=cx+(dx-cx)/3.0;
        double y2=cy+(dy-cy)/3.0;

        double x3=bx-(bx-ax)/3.0;
        double y3=by-(by-ay)/3.0;
        double x4=dx-(dx-cx)/3.0;
        double y4=dy-(dy-cy)/3.0;
//        double x1=(bx+2*ax)/3.0;
//        double y1=(by+2*ay)/3.0;
//        double x2=(dx+2*cx)/3.0;
//        double y2=(dy+2*cy)/3.0;
//
//        double x3=(2*bx+ax)/3.0;
//        double y3=(2*by+ay)/3.0;
//        double x4=(2*dx+cx)/3.0;
//        double y4=(2*dy+cy)/3.0;
        l = find_dis(x1,y1,x2,y2);
        r = find_dis(x3,y3,x4,y4);
//        cout<<l<<" "<<r<<endl;
        if(l>=r){
            ax=x1,ay=y1,cx=x2,cy=y2;//moving a to b, c to d
        }
        else{
            bx=x3,by=y3,dx=x4,dy=y4;//moving b to a, d to c
        }
    }
    return abs(l+r)/2.0;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy);
//        cin>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy;
        double ans=0.0;
        ans=ternary_search();
        //cout<<"Case "<<cs<<": "<<ans<<'\n';
        printf("Case %d: %f\n",cs,ans);
    }
    return 0;
}
/*
Let f(x) be a unimodal function on some interval [l; r]. Take any two points m1 and m2 in this segment: l < m1 < m2 < r. Then there are three possibilities:

if f(m1) < f(m2), then the required maximum can not be located on the left side - [l; m1].
    It means that the maximum further makes sense to look only in the interval [m1;r]
if f(m1) > f(m2), that the situation is similar to the previous, up to symmetry.
    Now, the required maximum can not be in the right side - [m2; r], so go to the segment [l; m2]
if f(m1) = f(m2), then the search should be conducted in [m1; m2],
    but this case can be attributed to any of the previous two (in order to simplify the code).
    Sooner or later the length of the segment will be a little less than a predetermined constant, and he process can be stopped.
    choice points m1 and m2:

m1 = l + (r-l)/3
m2 = r - (r-l)/3
Input:

Output:

*/
