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
vector<pair<int,int> >v;
int a[101];

int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    pair<int,int>dd;
    dd.first=0;
    dd.second=-1;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int a;
            scanf("%d",&a);
            if(dd.second<a){
                dd.second=a;
                dd.first=j;
            }
        }
//        cout<<dd.first<<endl;
//        v.push_back({dd.first,dd.second});
        a[dd.first]++;
        dd.first=0;
        dd.second=-1;
    }
//    int a[101];
    int k=0;
    int ans;
//    for(int i=0;i<v.size();i++){
////        cout<<v[i].first<<endl;
//        a[v[i].first]++;
////        cout<<a[v[i].first]<<endl;
//    }
    for(int i=1;i<=n;i++){
//        cout<<a[i]<<endl;
        if(a[i]>k){
            ans=i;
            k=a[i];
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*

*/
