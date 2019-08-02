/**
Algorithm :

1. Make a graph from input data and Determine the SCC of the graph.
2. Make a new Graph from SCC. Consider Each SCC as a node of this graph.
3. If any Node of SCC_graph have more than 1 out degree and It is not possible to traverse all node from the SCC which contain’s the node 0 of the input graph then Print “NO”.
4. Otherwise Print “YES”;
**/

#include<bits/stdc++.h>

using namespace std;

#define mx             100010
#define inf            0x3f3f3f3f
#define mod            1000000007
#define PI             2*acos(0.0)
#define E              2.71828182845904523536
#define ll             long long int
#define ull            unsigned long long int
#define pii            pair<int,int>
#define pll            pair<ll,ll>
#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
#define fast           ios_base::sync_with_stdio(false),cin.tie(NULL)
#define forstl(x)      for(__typeof(x.begin()) it=(x.begin());it!=(x.end());++it)
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
template <typename T> bool bitcheck(T p,T pos){return (bool)(p&(1<<pos));}
template <typename T> T biton(T p,T pos){return p=p|(1<<pos);}
template <typename T> T bitoff(T p,T pos){return p=p&~(1<<pos);}
template <typename T> ll toint(T s) {ll p;stringstream ss(s); ss>>p; return p;}
template <typename T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
template <typename T> T POW(T b,T p) {T Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
template <typename T> T BigMod(T b,T p,T Mod) {T Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
template <typename T> T ModInverse(T p,T Mod) {return BigMod(p,Mod-2,Mod);}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<int>edge[mx];
stack<int>st;
int low[mx],disc[mx],scc[mx];
bool vis[mx];
int cnt,colour;
set<int>ele;
void tarjan_scc(int u){
    vis[u]=true;
    st.push(u);
    low[u]=disc[u]=++cnt;
    forstl(edge[u]){
//        cout<<u<<" "<<*it<<endl;
        if(disc[*it]==-1){
            tarjan_scc(*it);
            low[u]=min(low[u],low[*it]);
        }
        else if(vis[*it]) low[u]=min(low[u],disc[*it]);
    }
    if(low[u]==disc[u]){
        int v;
        ++colour;
        do{
            v=st.top();
            st.pop();
            vis[v]=false;
            scc[v]=colour;
//            cout<<v<<" "<<colour<<endl;
        } while(v!=u);
    }
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    int t;
    cin>>t;
    for(int cs=1;cs<=t;cs++){
        cnt=0,colour=0;
        ele.clear();
        for(int i=0;i<mx;i++){
            edge[i].clear();
        }
        int n;
        cin>>n;
        while(n--){
            int k;
            cin>>k;
            while(k--){
                int u,v;
                cin>>u>>v;
                edge[u].push_back(v);
                ele.insert(u);
                ele.insert(v);
            }
        }
        mem(vis,false);
        mem(low,0);
        mem(disc,-1);
        mem(scc,0);
        forstl(ele){
            if(disc[*it]==-1) tarjan_scc(*it);
        }
        vector<int>in(mx,0);
        vector<int>out(mx,0);
        forstl(ele){
            for(int i=0;i<edge[*it].size();i++){
                int v=edge[*it][i];
                if(scc[*it]!=scc[v]){
                    out[scc[*it]]++;
                    in[scc[v]]++;
                }
            }
        }
        bool f=true;
        if(colour<=1){
            f=true;
        }
        else if(disc[0]==-1||in[scc[0]]!=0||out[scc[0]]!=1){
            f=false;
        }
        else{
            int sink=0;
            for(int i=1;i<=colour;i++){
                if(i==scc[0]) continue;
                if(in[i]==1&&out[i]==0){
                    sink++;
                    if(sink>1){
                        f=false;
                        break;
                    }
                }
                else{
                    if(in[i]==1&&out[i]==1) continue;
                    else{
                        f=false;
                        break;
                    }
                }

            }
        }
        if(f==false) printf("Case %d: NO\n",cs);
        else printf("Case %d: YES\n",cs);
    }
    return 0;
}
