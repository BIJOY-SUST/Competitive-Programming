/*
BIJOY
CSE-25th Batch
Shahjalal University of Science and Technology
*/
#include<bits/stdc++.h>
//#define pi             3.14159265358979323846264338328
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define ll             long long int
//#define llu            unsigned long long int
//#define mx             1000001
//#define mod            100000007
//const long long inf =  1e15;
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
using namespace std;
map<int,vector<int> >edges;
bool visited[101];
int ans1;
void DFS(int u){
    visited[u]=true;
    ans1++;
    for(int i=0;i<edges[u].size();i++){
        if(!visited[edges[u][i]]){
            DFS(edges[u][i]);
        }
    }
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n;
    while(scanf("%d",&n)==1){
        if(n==0) break;
        for(int i=1;i<=n;i++){
            int u;
            scanf("%d",&u);
            for(int j=1;j<=u;j++){
                int v;
                scanf("%d",&v);
                edges[i].push_back(v);
            }
        }
        int ans,mx=0;
        for(int i=1;i<=n;i++){
            memset(visited,false,sizeof(visited));
            ans1=0;
            DFS(i);
            if(mx<ans1){
                mx=ans1;
                ans=i;
            }
        }
        printf("%d\n",ans);
        for(int i=0;i<=n;i++) edges[i].clear();
    }
    return 0;
}
/*
Sample Input
3
1 2
1 3
0
4
2 2 4
0
2 2 4
0
0
Sample Output
1
1
*/
