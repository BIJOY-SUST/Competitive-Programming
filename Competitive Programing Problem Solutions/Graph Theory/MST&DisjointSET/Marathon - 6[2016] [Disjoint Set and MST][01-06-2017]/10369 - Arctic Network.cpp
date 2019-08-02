#include<bits/stdc++.h>
#define mx             1000
//#define mod            1000000007
//#define pi             2*acos(0.0)
#define ll             long long int
#define pp             pair<int,double>
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
class desh{
public:
    int u,v;
    double cost;
    bool operator<(const desh &p)const{
        return cost<p.cost;
    }
};
vector<pair<int,int> >node;
vector<desh>edges;
int par[mx];
int find_par(int x){
    return par[x]==x? x:find_par(par[x]);
}
double mst(int n,int r){
    sort(edges.begin(),edges.end());
    for(int i=1;i<=r;i++) par[i]=i;
    int cnt=r;
    double ans=0;
    for(int i=0;i<edges.size();i++){
        int pv=find_par(edges[i].u);
        int pu=find_par(edges[i].v);
        if(pu!=pv){
            ans=edges[i].cost;
            cnt--;
            par[pu]=pv;
//            cout<<edges[i].u<<" "<<edges[i].v<<" "<<edges[i].cost<<endl;
            if(cnt==n) break;
        }
    }
    return ans;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        mem(par,-1);
        node.clear();
        edges.clear();
        int n,r;
        scanf("%d%d",&n,&r);
        for(int i=0;i<r;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            node.push_back({x,y});
        }
        for(int i=0;i<r;i++){
            for(int j=i+1;j<r;j++){
                if(i!=j){
                    ll dis1=abs(node[i].first-node[j].first);
                    ll dis2=abs(node[i].second-node[j].second);
                    dis1=dis1*dis1;
                    dis2=dis2*dis2;
                    ll dis=dis1+dis2;
                    double d=(double)sqrt(dis);
                    desh ob;
                    ob.u=i+1;ob.v=j+1;ob.cost=d;
//                    cout<<d<<endl;
                    edges.push_back(ob);
//                    cout<<i+1<<" "<<j+1<<" "<<d<<endl;
                }
            }
        }
        double ans=mst(n,r);
        printf("%.2f\n",ans);
    }
    return 0;
}
/*

*/

