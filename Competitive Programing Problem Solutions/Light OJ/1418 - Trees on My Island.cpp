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
vector<pair<ll,ll> >point;
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        int n;
        scanf("%d",&n);
        ll x,y;
        for(int i=0;i<n;i++){
            scanf("%lld%lld",&x,&y);
            point.push_back(make_pair(x,y));
        }
        /* here
        A = area of polygoanal
        B = boundoury points of polygonal
        I = inside points of polygonal
        A=I+(B/2)-1.
        */
        ll B=__gcd(abs(point[n-1].first-point[0].first),abs(point[n-1].second-point[0].second));
        ll A=(point[n-1].first*point[0].second)-(point[0].first*point[n-1].second);
        for(int i=1;i<point.size();i++){
            B+=__gcd(abs(point[i-1].first-point[i].first),abs(point[i-1].second-point[i].second));
            A+=(point[i-1].first*point[i].second)-(point[i].first*point[i-1].second);
        }
        if(A<0) A=A*(-1);
        A*=.5;
//        cout<<A<<" "<<B<<endl;
        ll I=A+1-(B/2);
        printf("Case %d: %lld\n",cs,I);
        point.clear();
    }
    return 0;
}
/**
Input:
1

9

1 2

2 1

4 1

4 3

6 2

6 4

4 5

1 5

2 3
Output:

**/
