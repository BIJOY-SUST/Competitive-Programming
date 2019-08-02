#include<bits/stdc++.h>
//#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define p              pair<int,int>
//#define ll             long long int
//#define one(n)         _builtin_popcount(n)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool check(int n,int pos){return (bool)(n&(1<<pos));}
using namespace std;

bool IsBipartite(vector<int>edges[1000],int n){
    queue<int>q;
    q.push(n);
    int color[1000];
    memset(color,-1,sizeof(color));
    color[n]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        ///if(g[u][u]==1) return false;
        for(int i=0;i<edges[u].size();i++){
            int v=edges[u][i];
            if(color[v]==-1){
                color[v]=1-color[u];
                q.push(v);
            }
            else if(color[u]==color[v]){
                return false;
            }
        }
    }
    return true;
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n,e;
    while(cin>>n){
    if(n==0){
        break;
    }
    cin>>e;
    vector<int>edges[1000];
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    IsBipartite(edges,0) ? cout<<"BICOLORABLE."<<endl:cout<<"NOT BICOLORABLE."<<endl;
    }
    return 0;
}
