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
long double dis(ll x1,ll y1,ll x2,ll y2){
    return sqrt((long double)((x1-x2)*(x1-x2))+(long double)((y1-y2)*(y1-y2)));
}
ll area(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3){
    return (ll)(x1*y2+x2*y3+x3*y1-y1*x2-y2*x3-y3*x1);
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
        ll n;
        scanf("%lld",&n);
        for(ll i=0;i<n;i++){
            ll x,y;
            scanf("%lld%lld",&x,&y);
            point.push_back({x,y});
        }
        point.push_back({point[0].first,point[0].second});
        reverse(point.begin(),point.end());
        ll q;
        scanf("%lld",&q);
        bool is_inside=false;
        while(q--){
            ll x,y;
            scanf("%lld%lld",&x,&y);
            ll x3=x+1,y3=1e9+3;
            ll cnt=0;
            for(ll i=0;i<n;i++){
                ll x1=point[i].first,y1=point[i].second;
                ll x2=point[i+1].first,y2=point[i+1].second;
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
            for(ll i=0;i<n;i++){
                ll x1=point[i].first,y1=point[i].second;
                ll x2=point[i+1].first,y2=point[i+1].second;
                if(dis(x1,y1,x,y)+dis(x,y,x2,y2)==dis(x1,y1,x2,y2)){
                    f=true;
                }
            }
            if(cnt%2==0||f){
                is_inside=true;
            }
        }
        if(is_inside)printf("NO\n");
        else{
            printf("YES\n");
        }
    return 0;
}


