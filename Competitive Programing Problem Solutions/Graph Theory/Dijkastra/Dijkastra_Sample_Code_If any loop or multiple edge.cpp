/*
BIJOY
CSE-25th Batch
Shahjalal University of Science and Technology
*/
#include<bits/stdc++.h>
//#define pi             3.141592653589793238462643383
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define p              pair<llu,llu>
//#define ll             long long int
#define llu            unsigned long long int
#define mx             100005
//#define mod            100000007
#define inf            1e15
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
vector<p >edges[mx];
llu Distance[mx];
priority_queue<p,vector<p>,greater<p> >q;
int par[mx];
llu n;
llu Dijkstra(int start,int End){
    p u,v;
    for(int i=1;i<=n;i++) Distance[i]=inf;
    memset(par,-1,sizeof(par));
    q.push(make_pair(0,start));
    Distance[start]=0;
    while(!q.empty()){
        u=q.top();
        q.pop();
        if(u.first>Distance[u.second]) continue;
        for(int i=0;i<edges[u.second].size();i++){
            v = edges[u.second][i];
            if(Distance[u.second]+v.second<Distance[v.first]){
                Distance[v.first] = Distance[u.second]+v.second;
                q.push(make_pair(Distance[v.first],v.first));
                par[v.first]=u.second;
            }
        }
    }
    return Distance[End];
}
void printpath(int s){
    if(s==-1) return;
    printpath(par[s]);
    cout<<s <<" ";
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    llu e,start,End;
    cin>>n>>e>>start>>End;
    while(e--){
        llu u,v,w;
        cin>>u>>v>>w;
        edges[u].push_back(make_pair(v,w));
        edges[v].push_back(make_pair(u,w));
    }
    llu d = Dijkstra(start,End);
    if(par[n]!=-1){
        cout<<"Shortest Path: "<<d<<'\n';
        printpath(n);
        cout<<"\n";
    }
    else cout<<"-1\n";
    return 0;
}
/*
Input:
6
7 8 1 7
1 2 2
2 3 3
2 3 4
3 4 5
4 5 7
5 6 6
4 6 15
6 7 1
Output:
24
1 2 3 4 5 6 7
*/

