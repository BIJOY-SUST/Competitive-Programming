#include<bits/stdc++.h>
//#define mx             100010
//#define mod            1000000007
//#define pi             2*acos(0.0)
#define ll             long long int
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
    ll a,b,c;
    scanf("%lld%lld",&a,&b);
    c=a+b;
    ll aa=0,bb=0,cc=0,p=1;
    while(c>0){
        if(c%10==0){
            c=c/10;
        }
        else{
            ll remin=c%10;
            c=c/10;
            remin=remin*p;
            cc+=remin;
            p=p*10;
        }
    }
    p=1;
    while(a>0){
        if(a%10==0){
            a=a/10;
        }
        else{
            ll remin=a%10;
            a=a/10;
            remin=remin*p;
            aa+=remin;
            p=p*10;
        }
    }
    p=1;
    while(b>0){
        if(b%10==0){
            b=b/10;
        }
        else{
            ll remin=b%10;
            b=b/10;
            remin=remin*p;
            bb+=remin;
            p=p*10;
        }
    }
    if(aa+bb==cc){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    //cout<<aa<<" "<<bb<<" "<<cc<<endl;
    return 0;
}
/**
Input:

Output:

**/
