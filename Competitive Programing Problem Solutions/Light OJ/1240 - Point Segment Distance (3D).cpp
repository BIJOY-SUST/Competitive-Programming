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
double x1,k,z1,x2,y2,z2,x3,y3,z3;
double find_dis(double a,double b,double c,double d,double e,double f){
    return sqrt(((a-d)*(a-d))+((b-e)*(b-e))+((c-f)*(c-f)));
}
double ternary_search(){
    double l;//=find_dis(x1,k,z1,x3,y3,z3);
    double r;//=find_dis(x2,y2,z2,x3,y3,z3);
    int cnt=100;
    while(cnt--){
        double a=x1+(x2-x1)/3.0;
        double b=k+(y2-k)/3.0;
        double c=z1+(z2-z1)/3.0;
        double d=x2-(x2-x1)/3.0;
        double e=y2-(y2-k)/3.0;
        double f=z2-(z2-z1)/3.0;
        l = find_dis(a,b,c,x3,y3,z3);
        r = find_dis(d,e,f,x3,y3,z3);
        if(l>=r){
            x1=a,k=b,z1=c;
        }
        else{
            x2=d,y2=e,z2=f;
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
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&k,&z1,&x2,&y2,&z2,&x3,&y3,&z3);
        double ans=0.0;
        ans=ternary_search();
        printf("Case %d: %f\n",cs,ans);
    }
    return 0;
}
/**
Input:
2

0 0 1 0 1 1 0 1 0

0 0 0 1 1 1 0 0 1
Output:

**/
