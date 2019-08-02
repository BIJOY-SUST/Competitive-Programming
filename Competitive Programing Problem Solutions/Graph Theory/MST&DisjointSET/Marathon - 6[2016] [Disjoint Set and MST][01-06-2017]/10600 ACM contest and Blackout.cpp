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
int ans1;
vector<int>ans2;
map<int,int>parent;
vector<pair<int,int> >ms;
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
void MST(int n){
    sort(edges.begin(),edges.end());
    for(int i=0;i<=n;i++) parent[i]=i;
    int c=0;
    for(int i=0;i<edges.size();i++){
        int pu=find_par(edges[i].u);
        int pv=find_par(edges[i].v);
        if(pu!=pv){
            c++;
            parent[pu]=pv;
            ans1+=edges[i].w;
            ms.push_back(make_pair(edges[i].u,edges[i].v));
            if(c==n-1) break;
        }
    }
}
int second_mst(int n,int a,int b){
    int ans=0,c=0;
    for(int i=0;i<=n;i++) parent[i]=i;
    for(int i=0;i<edges.size();i++){
        if(edges[i].u==a&&edges[i].v==b) continue;
        else{
            int pu=find_par(edges[i].u);
            int pv=find_par(edges[i].v);
            if(pu!=pv){
                c++;
                ans+=edges[i].w;
                parent[pu]=pv;
                if(c==n-1){
                    ans2.push_back(ans);
                    break;
                }
            }
        }
    }
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        ans1=0;
        ans2.clear();
        ms.clear();
        edges.clear();
        parent.clear();
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<m;i++){
            int a,b,d;
            scanf("%d %d %d",&a,&b,&d);
            node ob;
            ob.u=a;
            ob.v=b;
            ob.w=d;
            edges.push_back(ob);
        }
        MST(n);
        for(int i=0;i<ms.size();i++){
            second_mst(n,ms[i].first,ms[i].second);
        }
        sort(ans2.begin(),ans2.end());
        printf("%d %d\n",ans1,ans2[0]);
    }
    return 0;
}
/*
Sample Input
2
5 8
1 3 75
3 4 51
2 4 19
3 2 95
2 5 42
5 4 31
1 2 9
3 5 66
9 14
1 2 4
1 8 8
2 8 11
3 2 8
8 9 7
8 7 1
7 9 6
9 3 2
3 4 7
3 6 4
7 6 2
4 6 14
4 5 9
5 6 10
Sample Output
110 121
37 37
*/
