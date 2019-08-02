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
        double a,b,c;
        scanf("%lf%lf%lf",&a,&b,&c);
        double d1;
        if(b!=0){
            d1=(a*c)/b;
            if(b!=d1){
                double d2=(a*c+a*d1+d1*c+d1*d1)/(b-d1);
                double d=d1+d2;
//                cout<<d1<<" "<<d2<<" "<<d<<endl;
                if(d>=0)printf("Case %d: %.6f\n",cs,d);
                else{
                    printf("Case %d: -1\n",cs);
                }
            }
            else{
                printf("Case %d: -1\n",cs);
            }
        }
        else{
            printf("Case %d: -1\n",cs);
        }
    }
    return 0;
}
/**
Input:

Output:

**/

