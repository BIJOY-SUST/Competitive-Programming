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
    cin>>t;
    for(int cs=1;cs<=t;cs++){
        double x,y,c;
        cin>>x>>y>>c;
        double l,h,mid;
        l=0.0,h=max(x,y);
        while(h-l>(1e-6)){
            mid=(l+h)/2.0;
            double h1,h2,w1,w2;
            h1=sqrt(x*x-mid*mid);
            h2=sqrt(y*y-mid*mid);
            w1=c*mid/h2;
            w2=c*mid/h1;
            if(w1+w2<mid){
                l=mid;
            }
            else h=mid;
        }
        cout<<setprecision(10)<<"Case "<<cs<<": "<<l<<'\n';
    }
    return 0;
}
/**
Input:

Output:

**/

