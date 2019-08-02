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
#define mx             100001
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
int n,e;
map<int,vector<int> >edges;
stack<int>st;
set<int>s;
bool visited[mx];
void dfs(int start){
    visited[start]=true;
    for(__typeof(edges[start].begin())it=edges[start].begin();it!=edges[start].end();it++){
        if(!visited[*it]) dfs(*it);
    }
    st.push(start);
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    while(scanf("%d%d",&n,&e)==2&&n!=0&&e!=0){
        memset(visited,false,sizeof(visited));
        for(int i=1;i<=e;i++){
            int u,v;scanf("%d%d",&u,&v);
            edges[u].push_back(v);
        }
        for(int i=1;i<=n;i++) s.insert(i);
        for(__typeof(s.begin())it=s.begin();it!=s.end();it++){
            if(!visited[*it]) dfs(*it);
        }
        while(!st.empty()){
            printf("%d ",st.top());
            st.pop();
        }
        printf("\n");
        for(int i=1;i<=n;i++) edges[i].clear();
        s.clear();
    }
    return 0;
}
/*
Sample Input
5 4
1 2
2 3
1 3
1 5
0 0
Sample Output
1 4 2 5 3
*/
