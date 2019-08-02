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
vector<pair<int,int> >v;
map<int,int>parent;
vector<pair<int,int> >ans;
class node{
public:
    int u,v;
    float w;
    bool operator<(const node &p)const{
        return w<p.w;
    }
};
vector<node>edges;
float find_w(pair<int,int>a,pair<int,int>b){
    int x=a.first-b.first;
    int y=a.second-b.second;
    return sqrt(x*x+y*y);
}
int find_par(int x){
    if(parent[x]!=x) parent[x]=find_par(parent[x]);
    else return parent[x];
}
void MST(int n,int m){
    sort(edges.begin(),edges.end());
    //int c=m;
    for(int i=0;i<edges.size();i++){
        int pu=find_par(edges[i].u);
        int pv=find_par(edges[i].v);
        if(pu!=pv){
            //c++;
            parent[pu]=pv;
            ans.push_back(make_pair(edges[i].u,edges[i].v));
            //if(c==n-1) break;
        }
    }
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        v.clear();
        edges.clear();
        parent.clear();
        ans.clear();
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            v.push_back(make_pair(a,b));
        }
        for(int i=1;i<=n;i++) parent[i]=i;
        int m;
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            u=find_par(u);
            v=find_par(v);
            parent[u]=v;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(find_par(i+1)!=find_par(j+1)){
                    node ob;
                    ob.u=i+1;
                    ob.v=j+1;
                    ob.w=find_w(v[i],v[j]);
                    edges.push_back(ob);
                }
            }
        }
        MST(n,m);
        if(ans.size()==0){
            printf("No new highways need\n");
        }
        else{
            for(int i=0;i<ans.size();i++){
                printf("%d %d\n",ans[i].first,ans[i].second);
            }
        }
        if(t>0) printf("\n");
    }
    return 0;
}
/*
Sample Input
1
9
1 5
0 0
3 2
4 5
5 1
0 4
5 2
1 2
5 3
3
1 3
9 7
1 2
Sample Output
1 6
3 7
4 9
5 7
8 3
*/
