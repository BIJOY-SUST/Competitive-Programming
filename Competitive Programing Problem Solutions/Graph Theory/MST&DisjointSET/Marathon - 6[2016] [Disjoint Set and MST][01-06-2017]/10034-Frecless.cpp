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
vector<pair<float,float> >v;
class node{
public:
    int u,v;
    float w;
    bool operator<(const node &p)const{
        return w<p.w;
    }
};
vector<node>edges;
map<int,int>parent;
float find_w(pair<float,float>a,pair<float,float>b){
    float x=a.first-b.first;
    float y=a.second-b.second;
    return sqrt(x*x+y*y);
}
int find_par(int x){
    if(parent[x]!=x) parent[x]=find_par(parent[x]);
    else return parent[x];
}
float MST(int n){
    sort(edges.begin(),edges.end());
    for(int i=0;i<n;i++) parent[i]=i;
    int c=0;
    float ans=0;
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
    int t;
    scanf("%d",&t);
    //printf("\n");
    while(t--){
        v.clear();
        edges.clear();
        parent.clear();
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            float a,b;
            scanf("%f%f",&a,&b);
            v.push_back(make_pair(a,b));
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                node ob;
                ob.u=i;
                ob.v=j;
                ob.w=find_w(v[i],v[j]);
                edges.push_back(ob);
            }
        }
//        for(int i=0;i<edges.size();i++)
//printf("%d %d %f\n",edges[i].u,edges[i].v,edges[i].w);
        float ans=MST(n);
        printf("%.2f\n",ans);
        if(t>0) printf("\n");
    }
    return 0;
}
/*

*/




























































///A basic Minimum Spanning Tree problem, refer to your algorithm book regarding how to compute MST, and now
///they change this problem to Multiple Input format. For those who got WA after re-judge, don't worry,
///just change your code into Multiple Input format and send again =)
