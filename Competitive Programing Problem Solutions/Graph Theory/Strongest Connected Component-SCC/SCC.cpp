#include<bits/stdc++.h>
#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define p              pair<int,int>
//#define ll             long long int
//#define one(n)         __builtin_popcount(n)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
using namespace std;
vector<int>m[mx];
vector<int>mm[mx];
map<int,int>finish;
bool vis[mx];
int cnt1=0,cnt2=0;
void dfs(int u){
    vis[u]=true;
    ++cnt1;
    for(int i=0;i<m[u].size();i++){
        int v=m[u][i];
        if(!vis[v]) dfs(v);
    }
    finish[u]=++cnt1;
}
void printcircle(int u){
    vis[u]=true;
    for(int i=0;i<mm[u].size();i++){
        int v=mm[u][i];
        if(!vis[v]) printcircle(v);
    }
    cout<<u<<" ";
}
bool comp(const pair<char,int>&a,const pair<char,int>&b){
    return a.second>b.second;
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        m[a].push_back(b);
        mm[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    dfs(1);
    vector<pair<int,int> >v(finish.begin(),finish.end());
    sort(v.begin(),v.end(),comp);
    memset(vis,false,sizeof(vis));
    for(int i=0;i<v.size();i++){
        if(!vis[v[i].first]){
            cnt2++;
            cout<<cnt2<<"-";
            printcircle(v[i].first);
            cout<<'\n';
        }
    }
    return 0;
}
/*
Input:
7 8
1 2 2 3 3 1 3 4 4 5 5 6 6 7 7 5
Output:
1-2 3 1
2-4
3-6 7 5
*/


