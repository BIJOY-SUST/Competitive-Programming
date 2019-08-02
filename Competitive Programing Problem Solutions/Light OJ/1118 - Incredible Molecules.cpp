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
        double x1,y1,r1,x2,y2,r2;
        scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&r1,&x2,&y2,&r2);
//        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        double c=1.0*sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
        double ans=0.0;
        if(r1+r2<=c){
            printf("Case %d: %.10f\n",cs,ans);
        }
        else if(c+r1<=r2){
            printf("Case %d: %.10f\n",cs,pi*r1*r1);
        }
        else if(c+r2<=r1){
            printf("Case %d: %.10f\n",cs,pi*r2*r2);
        }
        else{
            double theta=2.0*acos((r1*r1+c*c-r2*r2)/(2.0*r1*c));
            double ans1 = (r1*r1*0.5*(theta-sin(theta)));
            theta=2*acos((r2*r2+c*c-r1*r1)/(2.0*r2*c));
            double ans2 = (r2*r2*0.5*(theta-sin(theta)));
            ans=ans1+ans2;
//            cout<<ans<<endl;
            printf("Case %d: %.7f\n",cs,ans);
        }
    }
    return 0;
}
/**
Input:
3

0 0 10 15 0 10

-10 -10 5 0 -10 10

100 100 20 100 110 20
Output:

**/
