#include<bits/stdc++.h>
//#define pi             3.141592653589793238462643383
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define p              pair<int,int>
//#define ll             long long int
//#define llu            unsigned long long int
//#define mx             100001
//#define mod            100000007
//const long long inf =  1e15;
/*----------------------Graph Moves------------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
/*---------------------------------------------------*/
/*-----------------------Bitmask---------------------*/
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool check(int n,int pos){return (bool)(n&(1<<pos));}
/*---------------------------------------------------*/
using namespace std;
map<int,int>parent;
class node{
public:
    int u,v,w;
    bool operator<(const node &p)const{
        return w<p.w;
    }
};
vector<node>edges;
int find_par(int x){
    if(parent[x]!=x) parent[x]=find_par(parent[x]);
    else return parent[x];
}
int MST(int n){
    sort(edges.begin(),edges.end());
    for(int i=0;i<=n;i++) parent[i]=i;
    int c=0,ans,ans1=0,ans2=0;
    for(int i=0;i<edges.size();i++){
        int pu=find_par(edges[i].u);
        int pv=find_par(edges[i].v);
        if(pu!=pv){
            c++;
            parent[pu]=pv;
            ans1+=edges[i].w;
            if(c==n-1) break;
        }
    }
//    printf("%d\n",ans1);
    sort(edges.rbegin(),edges.rend());
    for(int i=0;i<=n;i++) parent[i]=i;
    c=0;
    for(int i=0;i<edges.size();i++){
        int pu=find_par(edges[i].u);
        int pv=find_par(edges[i].v);
        if(pu!=pv){
            c++;
            parent[pu]=pv;
            ans2+=edges[i].w;
            if(c==n-1) break;
        }
    }
    ans=ans1+ans2;
    return ans;
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        edges.clear();
        parent.clear();
        int n;
        scanf("%d",&n);
        while(1){
            int a,b,d;scanf("%d%d%d",&a,&b,&d);
            if(a==0&&b==0&&d==0) break;
            node ob;ob.u=a;ob.v=b;ob.w=d;
            edges.push_back(ob);
        }
        int ans=MST(n+1);
        if(ans&1) printf("Case %d: %d/2\n",cs,ans);
        else printf("Case %d: %d\n",cs,ans/2);
    }
    return 0;
}
/*
Input:
3

1
0 1 10
0 1 20
0 0 0

3
0 1 99
0 2 10
1 2 30
2 3 30
0 0 0

2
0 1 10
0 2 5
0 0 0
Output:
Case 1: 15
Case 2: 229/2
Case 3: 15
*/
