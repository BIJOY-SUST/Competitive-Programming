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
int grid[10][10];
bool visited[10][10];
vector<pair<int,int> >graph;
int ans;
int h=0;
bool isSafe(int r,int c){
    for(int i=0;i<graph.size();i++){
        int x=graph[i].first;
        int y=graph[i].second;
        if(r==x||c==y||(r+c)==(x+y)||(r-c)==(x-y))
            return false;
    }
    return true;
}
void back_t(int r){
    //cout<<graph.size()<<endl;
    if(r==8){
//        cout<<++h<<endl;
        int sum=0;
        for(int i=0;i<graph.size();i++){
            int x=graph[i].first;
            int y=graph[i].second;
            sum+=grid[x][y];
        }
        ans=max(ans,sum);
    }
    else{
        for(int c=0;c<8;c++){
            if(isSafe(r,c)){
//                cout<<r<<" "<<c<<endl;
                graph.push_back(make_pair(r,c));
                back_t(r+1);
                graph.pop_back();
            }
        }
    }
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        memset(grid,0,sizeof(grid));
        memset(visited,false,sizeof(visited));
        graph.clear();
        for(int i=0;i<8;i++) for(int j=0;j<8;j++)
            scanf("%d",&grid[i][j]);
        ans=0;
        back_t(0);
        printf("%5d\n",ans);
    }
    return 0;
}
/*

*/
