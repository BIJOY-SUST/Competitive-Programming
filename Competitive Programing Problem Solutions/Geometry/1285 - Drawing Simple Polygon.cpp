#include<bits/stdc++.h>
#define mx             2010
//#define mod            1000000007
#define pi             2*acos(0.0)
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
class point{
public:
    ll x,y,id;
};
point bindu[mx],Pivot;
ll orientation(point a,point b,point c){
    return ((b.y-a.y)*(c.x-b.x))-((c.y-b.y)*(b.x-a.x));
}
ll dis(point a,point b){
    return ((b.x-a.x)*(b.x-a.x))+((b.y-a.y)*(b.y-a.y));
}
bool cmp(point a,point b){
    ll val=orientation(Pivot,a,b);
    if(val==0){//checking co-linearity
        return dis(Pivot,a)<dis(Pivot,b);//if co-linear put nearest one
    }
//    return val>0;
    ll m1x=a.x-Pivot.x,m1y=a.y-Pivot.y;
    ll m2x=b.x-Pivot.x,m2y=b.y-Pivot.y;
    return (atan2((double)m1y,(double)m1x)-atan2((double)m2y,(double)m2x)<0);
}
void convexHull(ll n){
    ll ymin=bindu[0].y,in=0;
    for(int i=1;i<n;i++){//Finding the bottom-most point
        if(bindu[i].y<ymin||(ymin==bindu[i].y&&bindu[i].x<bindu[in].x)){
            ymin=bindu[i].y,in=i;
        }
    }
    swap(bindu[0],bindu[in]);//place the bottom-most point in the 1st position
    Pivot=bindu[0];
    sort(bindu,bindu+n,cmp);
    ll cnt=0;
    for(int i=n-2;i>=1;i--){
        if(orientation(Pivot,bindu[n-1],bindu[i])==0){
            continue;
        }
        else{
            cnt=i;
            break;
        }
    }
//    cout<<cnt<<endl;
    if(cnt==0){
        printf("Impossible\n");
    }
    else{
        reverse(bindu+cnt+1,bindu+n);
        for(int i=0;i<n;i++){
            if(i) printf(" %lld",bindu[i].id);
            else printf("%lld",bindu[i].id);
        }
        printf("\n");
    }
    return;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);

    ll t;
    scanf("%lld",&t);
    for(ll cs=1;cs<=t;cs++){
        ll n;
        scanf("%lld%",&n);
        for(ll i=0;i<n;i++){
            scanf("%lld%lld",&bindu[i].x,&bindu[i].y);
            bindu[i].id=i;
        }
        printf("Case %lld:\n",cs);
        convexHull(n);
    }
    return 0;
}
/**
Sample Input
1
5
2 1 0 0 1 1 3 3 3 1
Output for Sample Input
Case 1:
1 4 0 2 3(which is wrong if we don't use reverse function)
1 4 0 3 2(correct output)
**/


