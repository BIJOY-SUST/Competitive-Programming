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
    int n,cnt=0;
    scanf("%d",&n);
    while(cnt!=n){
        double a,b,c;
        scanf("%lf%lf%lf",&a,&b,&c);
        if(a*b*c<=0){
            printf("These are invalid inputs!\n");
            cnt++;
        }
        else{
            double d1,d2,d3,d4,A;
            d1=1/a;
            d2=1/b;
            d3=1/c;
            double m=d1+d2+d3,m1=-d1+d2+d3,m2=d1-d2+d3,m3=d1+d2-d3;
            A=m*m1*m2*m3;
            if(A<=0){
                printf("These are invalid inputs!\n");
                cnt++;
            }
            else{
                A=1/sqrt(A);
                printf("%.3f\n",A);
            }
        }
    }
    return 0;
}
/**
Hints:
http://isolvedaproblem.blogspot.com/2012/06/height-to-area-uva-10522.html
Input:

Output:

**/
