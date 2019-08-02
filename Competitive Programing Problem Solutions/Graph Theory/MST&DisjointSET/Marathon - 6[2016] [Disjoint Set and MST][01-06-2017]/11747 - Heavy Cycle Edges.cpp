#include<bits/stdc++.h>
#define mx             1010
//#define mod            1000000007
//#define pi             2*acos(0.0)
#define ll             long long int
//#define pp             pair<int,int>
//#define bug(x)         printf("X: %d\n",x)
//#define one(n)         __builtin_popcount(n)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
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
class node{
public:
    int x,y,w;
    bool operator<(const node &p)const{
        return w<p.w;
    }
};
vector<node>edges;
vector<int>cse;
int par[mx];
int find_par(int x){
    return par[x]==x? x:find_par(par[x]);
}
ll mst(int n){
    sort(edges.begin(),edges.end());
    for(int i=0;i<n;i++) par[i]=i;
    int cnt=0;
    ll ans=0;
    for(int i=0;i<edges.size();i++){
        int pu=find_par(edges[i].x);
        int pv=find_par(edges[i].y);
        if(pu!=pv){
            cnt++;
            par[pu]=pv;
            ans+=edges[i].w;
//            if(cnt==n-1) break;
        }
        else{
//            cout<<edges[i].w<<endl;
            cse.push_back(edges[i].w);
        }
    }
    return ans;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int m,n;
    while(scanf("%d%d",&m,&n)==2){
        if(n==0&&m==0) break;
//        ll sum=0;
        mem(par,-1);
        for(int i=0;i<n;i++){
            int u,v,d;
            scanf("%d%d%d",&u,&v,&d);
//            sum+=d;
            node ob;
            ob.x=u; ob.y=v; ob.w=d;
            edges.push_back(ob);
        }
        ll ans=mst(m);
//        ans=sum-ans;
        if(cse.size()==0){
            printf("forest\n");
        }
        else{
            for(int i=0;i<cse.size()-1;i++)
                printf("%d ",cse[i]);
            printf("%d\n",cse[cse.size()-1]);
        }
        cse.clear();
        edges.clear();
    }
    return 0;
}
/*

*/
