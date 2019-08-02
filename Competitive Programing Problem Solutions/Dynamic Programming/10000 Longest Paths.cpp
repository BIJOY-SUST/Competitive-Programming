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
int n,des;
map<int,vector<int> >edges;
int dd[101];
int BFS(int u){
    queue<int>q;
    q.push(u);
    memset(dd,0,sizeof(dd));
    int ans=0;
    while(!q.empty()){
        int p=q.front();
        q.pop();
        for(int i=0;i<edges[p].size();i++){
            int v=edges[p][i];
            if(dd[v]<dd[p]+1){
                dd[v]=dd[p]+1;
                q.push(v);
            }
        }

    }
///If there are several paths of maximum length, print the final place with smallest number.
    for(int i=1;i<=n;i++){
        if(ans<dd[i]){
            ans=dd[i];
            des=i;
        }
    }
    return ans;
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int tc=0;
    while(scanf("%d",&n)==1){
        if(tc) printf("\n");
        if(n==0) break;
        int start;
        scanf("%d",&start);
        while(1){
            int u,v;
            scanf("%d %d",&u,&v);
            if(u==0&&v==0) break;
            edges[u].push_back(v);
            //edges[v].push_back(u);
        }
        int ans=BFS(start);
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n",++tc,start,ans,des);
        for(int i=0;i<105;i++) edges[i].clear();
    }
    return 0;
}
