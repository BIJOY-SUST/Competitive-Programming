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

int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        double r1,r2,r3;
        scanf("%lf%lf%lf",&r1,&r2,&r3);
        double a=r1+r2;
        double b=r1+r3;
        double c=r2+r3;
        double ang_a=acos((b*b+c*c-a*a)/(2.0*b*c));
        double ang_b=acos((a*a+c*c-b*b)/(2.0*a*c));
        double ang_c=acos((a*a+b*b-c*c)/(2.0*a*b));
        double s=0.5*(a+b+c);
        double trangle_area=sqrt(s*(s-a)*(s-b)*(s-c));
//        cout<<trangle_area<<endl;
//        ang_a=ang_a*(180/pi);
//        ang_b=ang_b*(180/pi);
//        ang_c=ang_c*(180/pi);
        double area1=0.5*r1*r1*ang_c;
        double area2=0.5*r2*r2*ang_b;
        double area3=0.5*r3*r3*ang_a;
//        cout<<area1<<" "<<ang_c<<endl;
        double ans=trangle_area-area1-area2-area3;
        printf("Case %d: %.10f\n",cs,ans);
    }
    return 0;
}
/**
Input:

Output:

**/
