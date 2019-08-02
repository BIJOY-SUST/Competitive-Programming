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
map<int,vector<int> >edges;
map<int,vector<int> >weight;
map<int,int>visited;
void BFS(int c1){
    queue<int>q;
    q.push(c1);
    visited[c1]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        int size=edges[u].size();
        for(int i=0;i<size;i++){
            int v=edges[u][i];
            int max_sound=max(visited[u],weight[u][i]);
            if(max_sound<visited[v]){
                visited[v]=max_sound;
                q.push(v);
            }
        }
    }
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int C,S,Q,T=0;
    bool flag=true;
    while(1){
        cin>>C>>S>>Q;
        if(C==0&&S==0&&Q==0) break;
        for(int i=0;i<S;i++){
            int c1,c2,d;
            cin>>c1>>c2>>d;
            edges[c1].push_back(c2);
            edges[c2].push_back(c1);
            weight[c1].push_back(d);
            weight[c2].push_back(d);
        }
        if(flag==false) cout<<endl;
        flag=false;
        cout<<"Case #"<<++T<<endl;
        while(Q--){
            for(int j=0;j<=C;j++){
                visited[j]=100009;
            }
            int c1,c2;
            cin>>c1>>c2;
            BFS(c1);
            visited[c2]==100009?cout<<"no path"<<endl:cout<<visited[c2]<<endl;
            visited.clear();
        }
        edges.clear();
        weight.clear();
    }
    return 0;
}

