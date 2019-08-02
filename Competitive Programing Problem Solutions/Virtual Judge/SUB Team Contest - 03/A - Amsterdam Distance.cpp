#include<bits/stdc++.h>
//#define mx             100001
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
    int m,n;
    double r;
    cin>>m>>n>>r;
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    double e_r=(double)r/n;
        double ans=(y1+y2)*r/n;
        for(int i=1;i<=n;i++){
            double d=abs(x1-x2);
            double k=(double)m*2;
            double hh=(double)i;
            double rr=e_r*hh;
            double poridhi = (2.0)*pi*rr;
            poridhi=(double)(poridhi/k);
            poridhi=(double)poridhi*d;
            double dd=abs(y1-i)+abs(y2-i);
            dd=dd*e_r;
            poridhi=poridhi+dd;
            ans=min(ans,poridhi);
        }
        cout<<setprecision(10)<<ans<<endl;
    return 0;
}
/*
Input:

Output:

*/
