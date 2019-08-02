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
vector<pair<int,int> >point;
long double dis(int x1,int y1,int x2,int y2){
    return sqrt((long double)((x1-x2)*(x1-x2))+(long double)((y1-y2)*(y1-y2)));
}
ll area(int x1,int y1,int x2,int y2,int x3,int y3){
    return (ll)(x1*y2+x2*y3+x3*y1-y1*x2-y2*x3-y3*x1);
}
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
        point.push_back({point[0].first,point[0].second});
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",cs);
        while(q--){
            int x,y;
            scanf("%d%d",&x,&y);
            int x3=x+1,y3=20001;
            int cnt=0;
            for(int i=0;i<n;i++){
                int x1=point[i].first,y1=point[i].second;
                int x2=point[i+1].first,y2=point[i+1].second;
                ll ans1=area(x,y,x3,y3,x1,y1);
                ll ans2=area(x,y,x3,y3,x2,y2);
                ll ans3=area(x1,y1,x2,y2,x,y);
                ll ans4=area(x1,y1,x2,y2,x3,y3);
//                cout<<ans1<<" "<<ans2<<" "<<ans3<<" "<<ans4<<endl;
                if(ans1*ans2<0){
                    if(ans3*ans4<0){
                        cnt++;
                    }
                }
            }
            bool f=false;
            for(int i=0;i<n;i++){
                int x1=point[i].first,y1=point[i].second;
                int x2=point[i+1].first,y2=point[i+1].second;
                if(dis(x1,y1,x,y)+dis(x,y,x2,y2)==dis(x1,y1,x2,y2)){
                    f=true;
                }
            }
            if(cnt%2||f) printf("Yes\n");
            else printf("No\n");
        }
        point.clear();
    }
    return 0;
}
/**
Input:
2

3

0 0 10 0 0 20

2

5 5

10 10

3

0 0 3 3 0 3

1

5 5
Output:

**/

