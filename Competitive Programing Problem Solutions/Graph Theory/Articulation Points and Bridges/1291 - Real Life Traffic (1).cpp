#include<bits/stdc++.h>
#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
#define pp             pair<int,int>
//#define ll             long long int
#define me             printf("BIJOY\n");
//#define one(n)         __builtin_popcount(n)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
//disclate< class T > inline T SQR(T a) {return ((a)*(a));}
//disclate< class T > inline T gcd(T a,T b) {a=abs(a);b=abs(b); if(!b) return a; return gcd(b,a%b);}
//disclate< class T > inline T lcm(T a,T b) {a=abs(a);b=abs(b); return (a/_gcd(a,b))*b;}
//disclate<typename T> T POW(T b,T p) {T r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
//disclate<typename T> T BigMod(T b,T p,T m) {T r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
//disclate<typename T> T ModInverse(T n,T m) {return BigMod(n,m-2,m);}
using namespace std;
vector<int>edges[mx];
int parent[mx],child[mx],low[mx],disc[mx],mark[mx];
bool vis[mx],is_cut[mx];
int c,color;
stack<int>st;
void BCC(int u){
    vis[u]=true;
    low[u]=disc[u]=++c;
    st.push(u);
    //cout<<u<<" "<<low[u]<<" "<<disc[u]<<endl;
    for(int i=0;i<edges[u].size();i++){
        int v=edges[u][i];
        if(v==parent[u]) continue;
        else if(!vis[v]){
//            child[u]++;
            parent[v]=u;
            BCC(v);
            low[u]=min(low[u],low[v]);
//            if(parent[u]==-1&&child[u]>1) is_cut[u]=true;
//            if(low[v]>disc[u])
//                is_cut[u]=true;
        }
        else low[u]=min(low[u],disc[v]);
    }
    //cout<<u<<" "<<low[u]<<" "<<disc[u]<<endl;

    if(low[u]==disc[u]){
        while(st.size()){
            int v=st.top();
            st.pop();
            mark[v]=color;
            //cout<<"item "<<v<<" color:"<<color<<endl;
            if(v==u) break;
        }
        color++;
    }
    return;
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t; scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        int n,e; scanf("%d %d",&n,&e);
        for(int i=1;i<=e;i++){
            int u,v; scanf("%d %d",&u,&v);
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        mem(parent,-1);
        mem(low,0);
        mem(disc,0);
        mem(child,0);
        mem(vis,false);
//        mem(is_cut,false);
        mem(mark,-1);
        c=0,color=0;
        BCC(0);
        for(int i=0;i<n;i++){
            for(int j=0;j<edges[i].size();j++){
                if(mark[edges[i][j]]!=mark[i])
                    child[mark[i]]++;
            }
        }
        int ans=1;
//        cout<<mark[2]<<" "<<mark[3]<<endl;
        for(int i=0;i<color;i++){
            if(child[i]==1) ans++;
        }
        printf("Case %d: %d\n",cs,ans/2);
        for(int i=0;i<mx;i++) edges[i].clear();
        while(st.size()) st.pop();
    }
    return 0;
}
/*
Input:
2



4 3

1 2

2 3

2 0



3 3

1 2

2 0

0 1
Output:
Case 1: 2

Case 2: 0
*/
