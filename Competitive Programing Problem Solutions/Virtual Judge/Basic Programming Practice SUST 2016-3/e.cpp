#include<bits/stdc++.h>
//#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define ll             long long int
//#define pp             pair<int,int>
//#define bug(x)         printf("X: %d\n",x)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
//ll POW(ll b,ll p) {ll r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
//ll BigMod(ll b,ll p,ll m) {ll r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
//ll ModInverse(ll n,ll m) {return BigMod(n,m-2,m);}
using namespace std;

int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    scanf("%d",&n);
    int x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    int d=n-x1-x2-x3;
    int a,b,c;
    a=x1; b=x2; c=x3;
    if(y1-x1>=d){
        a+=d;
    }
    else{
        int k=y1-x1;
        a+=k;
        d=d-(y1-x1);
        if(y2-x2>=d){
            b+=d;
        }
        else{
            k=y2-x2;
            b+=k;
            d=d-(y2-x2);
            if(y3-x3>=d){
                c+=d;
            }
            else{
                k=y3-x3;
                c+=k;
                d=d-(y3-x3);
            }
        }
    }
    printf("%d %d %d\n",a,b,c);
    return 0;
}
/*

*/
