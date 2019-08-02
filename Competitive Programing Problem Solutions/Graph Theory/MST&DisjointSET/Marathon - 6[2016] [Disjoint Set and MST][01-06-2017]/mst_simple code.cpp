#include<bits/stdc++.h>
//#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define pp             pair<int,int>
//#define ll             long long int
//#define bug(x)         printf("X: %d\n",x)
//#define one(n)         __builtin_popcount(n)
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
class edge{
public:
    int w;
    char u,v;
    bool operator<(const edge &p)const{
        return w<p.w;
    }
};
vector<edge>e;
map<char,int>representative;
int find_par(int x){
    if(representative[x]!=x) return representative[x]=find_par(representative[x]);
    return representative[x];
}
int MST(int n){
    sort(e.begin(),e.end());
    for(char i='a';i<=97+n;i++){
        representative[i]=i;
    }
    int c=0,ans=0;
    for(int i=0;i<(int)e.size();i++){
        int pu=find_par(e[i].u);
        int pv=find_par(e[i].v);
        if(pu!=pv){
            representative[pu]=pv;
            c++;
            ans+=e[i].w;
            if(c==n-1){
                break;
            }
        }
    }
    return ans;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int w;
        char u,v;
        cin>>u>>v>>w;
        edge ob;
        ob.u=u;
        ob.v=v;
        ob.w=w;
        e.push_back(ob);
    }
    cout<<MST(n)<<endl;
    return 0;
}
/*

*/
