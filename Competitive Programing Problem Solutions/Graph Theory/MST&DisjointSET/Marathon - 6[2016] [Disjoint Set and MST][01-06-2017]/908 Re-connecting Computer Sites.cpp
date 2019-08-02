/*
BIJOY
CSE-25th Batch
Shahjalal University of Science and Technology
*/
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
class node{
public:
    int u,v,w;
    bool operator<(const node &p)const{
        return w<p.w;
    }
};
vector<node>edges;
set<int>s;
map<int,int>parent;
int find_par(int x){
    if(parent[x]!=x) parent[x]=find_par(parent[x]);
    else return parent[x];
}
int MST(int n){
    sort(edges.begin(),edges.end());
    for(__typeof(s.begin())it=s.begin();it!=s.end();it++){
        parent[*it]=*it;
    }
    int c=0,ans=0;
    for(int i=0;i<edges.size();i++){
        int pu=find_par(edges[i].u);
        int pv=find_par(edges[i].v);
        if(pu!=pv){
            c++;
            parent[pu]=pv;
            ans+=edges[i].w;
            if(c==n-1) break;
        }
    }
    return ans;
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n;
    bool flag=true;
    while(scanf("%d",&n)!=EOF){
        edges.clear();
        parent.clear();
        s.clear();
        node ob;
        for(int i=1;i<n;i++){
            int a,b,d;
            scanf("%d %d %d",&a,&b,&d);
            ob.u=a;
            ob.v=b;
            ob.w=d;
            edges.push_back(ob);
            s.insert(a);
            s.insert(b);
        }
        int ans1=MST(n);
        edges.clear();
        parent.clear();
        s.clear();
        int k;
        scanf("%d",&k);
        for(int i=1;i<=k;i++){
            int a,b,d;
            scanf("%d %d %d",&a,&b,&d);
            ob.u=a;
            ob.v=b;
            ob.w=d;
            edges.push_back(ob);
            s.insert(a);
            s.insert(b);
        }
        int m;
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            int a,b,d;
            scanf("%d %d %d",&a,&b,&d);
            ob.u=a;
            ob.v=b;
            ob.w=d;
            edges.push_back(ob);
            s.insert(a);
            s.insert(b);
        }
        int ans2=MST(n);
        if(flag) flag=false;
        else printf("\n");
        printf("%d\n%d\n",ans1,ans2);
    }
    return 0;
}
/*
Sample Input
5
1 2 5
1 3 5
1 4 5
1 5 5
1
2 3 2
6
1 2 5
1 3 5
1 4 5
1 5 5
3 4 8
4 5 8
Sample Output
20
17
*/
