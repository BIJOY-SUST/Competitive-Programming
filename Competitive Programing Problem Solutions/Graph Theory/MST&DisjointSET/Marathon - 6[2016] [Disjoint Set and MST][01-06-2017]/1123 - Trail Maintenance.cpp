#include<bits/stdc++.h>
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define p              pair<int,int>
//#define ll             long long int
//#define llu            unsigned long long int
//#define mx             100001
//#define mod            100000007
//const long long inf =  1e15;
//----------------------Graph Moves--------------------
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//-----------------------------------------------------
//-----------------------Bitmask-----------------------
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool check(int n,int pos){return (bool)(n&(1<<pos));}
//-----------------------------------------------------
using namespace std;
int parent[210];
class node{
public:
    int u,v,w;
    bool operator<(const node &p)const{
        return w<p.w;
    }
    node(int x,int y,int z){
        u=x,v=y,w=z;
    }
};
vector<node>edges;
int find_par(int x){
    if(parent[x]!=x) return parent[x]=find_par(parent[x]);
    else return parent[x];
}
int MST(int n){
    vector<node>edges2;
    sort(edges.begin(),edges.end());
    for(int i=0;i<=n;i++) parent[i]=i;
    int c=0,ans=0;
    for(int i=0;i<edges.size();i++){
        int pu=find_par(edges[i].u);
        int pv=find_par(edges[i].v);
        if(pu!=pv){
            c++;
            parent[pu]=pv;
            ans+=edges[i].w;
            edges2.push_back(edges[i]);
            if(c==n-1) break;
        }
    }
    edges.clear();
    edges=edges2;
    edges2.clear();
    if(c==n-1) return ans;
    else return -1;
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        edges.clear();
        //parent.clear();
        printf("Case %d:\n",cs);
        int n,e,c=0;
        scanf("%d%d",&n,&e);
        for(int i=1;i<=e;i++){
            int a,b,d;
            scanf("%d%d%d",&a,&b,&d);
            edges.push_back(node(a,b,d));
            c++;
            if(c<n-1) printf("-1\n");
            else{
                int ans=MST(n);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
/*
Sample Input
1
4 6
1 2 10
1 3 8
3 2 3
1 4 3
1 3 6
2 1 2
Output for Sample Input
Case 1:
-1
-1
-1
14
12
8
*/
