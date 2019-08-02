#include<bits/stdc++.h>
#define mx             100010
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
    ll x,y;
};
point bindu[mx],Pivot;
stack<point>st;
vector<point>ans;
map<pair<ll,ll>,ll >ind_val;
ll orientation(point a,point b,point c){
    return ((b.y-a.y)*(c.x-b.x))-((c.y-b.y)*(b.x-a.x));
}
ll dis(point a,point b){
    return ((b.x-a.x)*(b.x-a.x))+((b.y-a.y)*(b.y-a.y));
}
bool cmp(point a,point b){
    if(orientation(Pivot,a,b)==0){//checking co-linearity
        return dis(Pivot,a)<dis(Pivot,b);//if co-linear put nearest one
    }
    ll m1x=a.x-Pivot.x,m1y=a.y-Pivot.y;
    ll m2x=b.x-Pivot.x,m2y=b.y-Pivot.y;
    return (atan2((double)m1y,(double)m1x)-atan2((double)m2y,(double)m2x)<0);
}
point nextToTop(){
    point a=st.top();
    st.pop();
    point b=st.top();
    st.push(a);
    return b;
}
void convexHull(ll n){
    ll ymin=bindu[0].y,mn=0;
    for(int i=1;i<n;i++){//Finding the bottom-most point
        if(bindu[i].y<ymin||(ymin==bindu[i].y&&bindu[i].x<bindu[mn].x)){
            ymin=bindu[i].y,mn=i;
        }
    }
    swap(bindu[0],bindu[mn]);//place the bottom-most point in the 1st position
    Pivot=bindu[0];
    sort(bindu,bindu+n,cmp);
    ll m=1;
    for(int i=1;i<n;i++){
        while(i<n-1&&orientation(Pivot,bindu[i],bindu[i+1])==0) i++;//removing same angle points
        bindu[m++]=bindu[i];
    }
//    cout<<m<<endl;
    if(m<3){//Convex Hull is not possible
        if(m==1){
            printf("%.2f\n",0.0);
            printf("1\n");
            return;
        }
        if(m==2){
//            cout<<(double)dis(bindu[0],bindu[1])<<endl;
            double ret=(sqrt((double)dis(bindu[0],bindu[1]))*(double)2);
            printf("%.2f\n",ret);
            printf("%d ",ind_val[{bindu[0].x,bindu[0].y}]);
            printf("%d\n",ind_val[{bindu[1].x,bindu[1].y}]);
            return;
        }
    }
    st.push(bindu[0]);
    st.push(bindu[1]);
    st.push(bindu[2]);
    for(int i=3;i<m;i++){
        while(orientation(nextToTop(),st.top(),bindu[i])>=0) st.pop();
        st.push(bindu[i]);
    }
    while(!st.empty()){
        point a=st.top();
        ans.push_back(a);
//        cout<<a.x<<" "<<a.y<<endl;
        st.pop();
    }
    ans.push_back(ans[0]);
    double ret=0.0;
    for(int i=1;i<ans.size();i++){
//        cout<<ans[i].x<<" "<<ans[i].y<<endl;
        ret+=sqrt((double)dis(ans[i],ans[i-1]));
    }
    printf("%.2f\n",ret);
    reverse(ans.begin(),ans.end());
    for(int i=1;i<ans.size();i++){
        if(i==ans.size()-1) printf("%d\n",ind_val[{ans[i].x,ans[i].y}]);
        else printf("%d ",ind_val[{ans[i].x,ans[i].y}]);
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
        for(int i=0;i<n;i++){
            scanf("%lld%lld",&bindu[i].x,&bindu[i].y);
            if(ind_val[{bindu[i].x,bindu[i].y}]==0)
                ind_val[{bindu[i].x,bindu[i].y}]=i+1;
        }
        printf("\n");
        convexHull(n);
        ans.clear();
        ind_val.clear();
    }
    return 0;
}
/**
Input:
8

5
0 0
0 5
10 5
3 3
10 0

1
0 0

3
0 0
1 0
2 0

4
0 0
0 0
0 1
1 0

3
0 0
0 1
1 0

6
0 0
-1 -1
1 1
2 2
3 3
4 4

2
10 0
0 0

7
-3 -4
2 -3
4 3
-4 2
0 5
2 -3
-1 4

Output:
30.00
1 5 3 2

0.00
1

4.00
1 3

3.41
1 4 3

3.41
1 3 2

14.14
2 6

20.00
2 1

26.98
1 2 3 5 4

**/


