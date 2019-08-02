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
set<int>s;
bool visited[mx],visited2[mx];
map<int,int>finish;
int cnt=0,cnt2=0;
void dfs(int u){
    ++cnt;
    visited[u]=true;
    for(int i=0;i<edges[u].size();i++){
        int v=edges[u][i];
        if(!visited[v]) dfs(v);
    }
    finish[u]=++cnt;
}
bool compare(const pair<int,int>&a,const pair<int,int>&b){
    return a.second<b.second;
}
void printSCC(int u){
    visited2[u]=true;
    for(int i=0;i<edges[u].size();i++){
        int v=edges[u][i];
        if(!visited2[v]) dfs(v);
    }
        printf(" %d",u);
}
int main(){
    scanf("%d%d",&n,&e);
    for(int i=1;i<=e;i++){
        int u,v;scanf("%d%d",&u,&v);
        edges[u].push_back(v);
        edges[v].push_back(u);
        s.insert(u);
        s.insert(v);
    }
    memset(visited,false,sizeof(visited));
    for(__typeof(s.begin())it=s.begin();it!=s.end();it++){
        if(*it) dfs(*it);
    }
    vector<pair<int,int> >v(finish.begin(),finish.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size();i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    memset(visited,false,sizeof(visited2));
    for(__typeof(v.begin())it=v.begin();it!=v.end();it++){
        if(!visited2[it->first]){
            printf("Strongly Connected Component %d: ",++cnt2);
            printSCC(it->first);
            printf("\n");
        }
    }
    return 0;
}
/**
Input:
7 10
1 2
2 3
3 1
2 4
3 7
4 5
5 4
5 6
6 7
7 6
Output:
1-7 8
2-4 5
3-2 1 3
**/
