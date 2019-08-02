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
        vector<pair<int,int> >point;
        for(int i=0;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            point.push_back({x,y});
        }
        ll ans=0;
        map<pair<int,int>,ll >mp;
        for(int i=0;i<n;i++){
            mp.clear();
            for(int j=0;j<n;j++){
                int x1=point[i].first,y1=point[i].second;
                int x2=point[j].first,y2=point[j].second;
                if(i!=j){
                    int x=x1-x2;
                    int y=y1-y2;
                    if(x<0) x*=(-1),y*=(-1);
                    int d=__gcd(x,y);
                    x/=d;
                    y/=d;
                    mp[{x,y}]++;
                    ll cnt=mp[{x,y}];
                    ans=max(ans,cnt);
                }
            }
        }
        printf("Case %d: %d\n",cs,ans+1);
        point.clear();
    }
    return 0;
}
/**
Input:
2

5

1 1

2 2

2 9

3 10

10 17

3

5 6

6 7

2 8
Output:

**/

