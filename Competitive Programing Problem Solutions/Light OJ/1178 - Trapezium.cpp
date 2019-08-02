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
        double aa,bb,cc,dd;
        scanf("%lf%lf%lf%lf",&aa,&bb,&cc,&dd);
        double a=aa>cc?cc:aa;
        double b=aa>cc?aa:cc;
        double c=dd;
        double d=bb;
//        cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
//        double p=(a*b*b-a*a*b-a*c*c+b*d*d);
////        cout<<p<<endl;
//        double q=(a*b*b-a*a*b-a*d*d+b*c*c);
////        cout<<q<<endl;
//        double d1=(p*q)/(4.0*(b-c)*(b-c));
//        double d2=(b*b+d*d-a*a-c*c);
//        d2=(d2*d2)/16.0;
//        double ans=d1-d2;
//        ans=sqrt(ans);
/**The 7th-century Indian mathematician Bhāskara
I derived the following formula for the area of a trapezoid with consecutive sides a, c, b, d:
where a and b are parallel and b > a**/
        double m=(-a+b+c+d);
        double n=(a-b+c+d);
        double o=(a-b+c-d);
        double p=(a-b-c+d);
        double dq=sqrt(m*n*o*p);
        dq=dq*(a+b);
        dq=dq/(4.0*(b-a));
        printf("Case %d: %.10f\n",cs,dq);
    }
    return 0;
}
/**
Input:
2

6 5 12 5.0

9 5 6 4
Output:

**/
