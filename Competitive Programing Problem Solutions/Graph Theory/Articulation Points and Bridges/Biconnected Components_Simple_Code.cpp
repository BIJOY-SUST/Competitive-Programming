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
//template< class T > inline T SQR(T a) {return ((a)*(a));}
//template< class T > inline T gcd(T a,T b) {a=abs(a);b=abs(b); if(!b) return a; return gcd(b,a%b);}
//template< class T > inline T lcm(T a,T b) {a=abs(a);b=abs(b); return (a/_gcd(a,b))*b;}
//template<typename T> T POW(T b,T p) {T r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
//template<typename T> T BigMod(T b,T p,T m) {T r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
//template<typename T> T ModInverse(T n,T m) {return BigMod(n,m-2,m);}
using namespace std;
vector<int>edges[mx];
int par[mx],low[mx],disc[mx],child[mx];
bool vis[mx],is_cut[mx];
int c,ans;
stack<pp >st;
void BCC(int u){
    vis[u]=true;
    low[u]=disc[u]=++c;
    for(int i=0;i<edges[u].size();i++){
        int v=edges[u][i];
        if(!vis[v]){
            child[v]++;
            par[v]=u;
            st.push(make_pair(u,v));
            BCC(v);
            low[u]=min(low[u],low[v]);
            if((par[u]==-1&&child[u]>1)||(par[u]!=-1&&low[v]>=disc[u])){
                while(u!=st.top().first||st.top().second!=v){
                    cout<<st.top().first<<"--"<<st.top().second<<" ";
                    st.pop();
                }
                cout<<st.top().first<<"--"<<st.top().second<<" ";
                st.pop();
                cout<<endl;
                ans++;
//                me
            }
        }
        else if(v!=par[u]&&disc[v]<low[u]){
            low[u]=min(low[u],disc[v]);
            st.push(make_pair(u,v));
        }
    }
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n,e; scanf("%d %d",&n,&e);
    for(int i=1;i<=e;i++){
        int u,v; scanf("%d %d",&u,&v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    mem(par,-1);
    mem(low,0);
    mem(disc,0);
    mem(child,0);
    mem(vis,false);
    mem(is_cut,false);
    c=0,ans=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            BCC(i);
        }
        bool flag=false;
        while(st.size()){
            flag=true;
            cout<<st.top().first<<"--"<<st.top().second<<" ";
            st.pop();
        }
        if(flag){
            cout<<'\n';
            ans++;
//            me
        }
    }
    cout<<"Above are "<<ans<<" biconnected components in graph"<<'\n';
    return 0;
}
/*
Input:
12 14
0 1 1 2 1 3 2 3 2 4 3 4 1 5 0 6 5 6 5 7 5 8 7 8 8 9 10 11
Output:
4--2 3--4 3--1 2--3 1--2
8--9
8--5 7--8 5--7
6--0 5--6 1--5 0--1
10--11
Above are 5 biconnected components in graph
*/
