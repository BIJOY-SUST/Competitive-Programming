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
        double ab,bc,ac,r;
        cin>>ab>>ac>>bc>>r;
        double l=0.0,h=ab;
        double s=(ab+bc+ac)/2.0;
        double abc=sqrt(s*(s-ab)*(s-bc)*(s-ac));
        double ad,ae,de;
        while(h-l>(1e-6)){
            double mid=(l+h)/2.0;
            double t_r=mid/ab;
            ad=mid;
            ae=t_r*ac;
            de=t_r*bc;
            s=(ad+ae+de)/2.0;
            double ade=sqrt(s*(s-ad)*(s-ae)*(s-de));
            double bdec=abc-ade;
            if((ade/bdec)<r) l=mid;
            else h=mid;
        }
        cout<<setprecision(10)<<"Case "<<cs<<": "<<l<<'\n';
    }
    return 0;
}
/**
Input:
4

100 100 100 2

10 12 14 1

7 8 9 10

8.134 9.098 7.123 5.10
Output:
Case 1: 81.6496580

Case 2: 7.07106781

Case 3: 6.6742381247

Case 4: 7.437454786
**/
