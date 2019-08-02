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
    double a,b,c;
    while(scanf("%lf%lf%lf",&a,&b,&c)==3){
    double s=(a+b+c)/2.0;
    double trangle_area=sqrt(s*(s-a)*(s-b)*(s-c));
//    cout<<trangle_area<<" "<<s<<endl;
    if(trangle_area<0) trangle_area*=(-1);
    double big_circle=(a*b*c)/(4*trangle_area);
    big_circle=pi*big_circle*big_circle;
    double small_circle=(trangle_area/s);
    small_circle=pi*small_circle*small_circle;
    printf("%.4f %.4f %.4f\n",big_circle-trangle_area,trangle_area-small_circle,small_circle);
    }
    return 0;
}
/**
Input:

Output:

**/
