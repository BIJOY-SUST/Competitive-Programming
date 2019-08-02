#include<bits/stdc++.h>
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define p              pair<int,int>
//#define ll             long long int
//#define llu            unsigned long long int
//#define mx             100001
//#define mod            100000007
//const long long inf =  1e15;
//----------------------Graph Moves--------------------
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//-----------------------------------------------------
//-----------------------Bitmask-----------------------
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool check(int n,int pos){return (bool)(n&(1<<pos));}
//-----------------------------------------------------
using namespace std;
//int grid[10][10];
//bool visited[10][10];
vector<pair<int,int> >graph;
vector<vector<int> >sol;
bool isSafe(int r,int c){
    for(int i=0;i<graph.size();i++){
        int x=graph[i].first;
        int y=graph[i].second;
        if(r==x||c==y||(r+c)==(x+y)||(r-c)==(x-y))
            return false;
    }
    return true;
}
void back_t(int c,int u,int v){
    //cout<<graph.size()<<endl;
    if(c==v) back_t(c+1,u,v);
    if(graph.size()==8){
//        cout<<graph.size()<<endl;
        vector<int>vv;
        int k=graph[0].first;
        //if(v==1) vv.push_back(k);
        for(int i=1;i<graph.size();i++){
            int x=graph[i].first;
//            int y=graph[i].second;
            if(i==v){
                vv.push_back(k);
                vv.push_back(x);
            }
            else vv.push_back(x);
        }
        if(v==8) vv.push_back(k);
        sol.push_back(vv);
        return;
//        ans=max(ans,sum);
    }
    for(int r=1;r<=8;r++){
        if(isSafe(r,c)){
            //cout<<r<<" "<<c<<endl;
            graph.push_back(make_pair(r,c));
            back_t(c+1,u,v);
            graph.pop_back();
        }
    }
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
//        memset(grid,0,sizeof(grid));
//        memset(visited,false,sizeof(visited));
        graph.clear();
        sol.clear();
        int u,v;
        scanf("%d%d",&u,&v);
//        visited[u][v]=true;
        graph.push_back(make_pair(u,v));
//        for(int i=0;i<8;i++) for(int j=0;j<8;j++)
//            scanf("%d",&grid[i][j]);
        back_t(1,u,v);
        sort(sol.begin(),sol.end());
        sol.erase(unique(sol.begin(),sol.end()),sol.end());
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        for(int i=0;i<sol.size();i++){
            printf("%2d     ",i+1);
            for(int j=0;j<sol[i].size();j++){
                printf(" %d",sol[i][j]);
            }
            printf("\n");
        }
        if(cs!=t) printf("\n");
    }
    return 0;
}
/*

*/

