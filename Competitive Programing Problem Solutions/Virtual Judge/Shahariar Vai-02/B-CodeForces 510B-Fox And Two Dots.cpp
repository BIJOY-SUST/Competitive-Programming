#include<bits/stdc++.h>
#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define p              pair<int,int>
//#define ll             long long int
//#define one(n)         _builtin_popcount(n)
//#define ull            unsigned long long int
#define valid(tx,ty)   tx>=0&&tx<n&&ty>=0&&ty<m
const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool check(int n,int pos){return (bool)(n&(1<<pos));}
using namespace std;
char v[55][55];
bool visited[mx];
bool vis[55][55];
int n,m;
char ch;
bool dfs(int x,int y,int p_f,int p_s){
    vis[x][y]=true;
    for(int i=0;i<4;i++){
        int tx=x+fx[i];
        int ty=y+fy[i];
        if(valid(tx,ty)){
            if(v[tx][ty]==ch){
                if(!vis[tx][ty]){
                    if(dfs(tx,ty,x,y)){
                        return true;
                    }
                }
                else if(tx!=p_f&&ty!=p_s) return true;
            }
        }
    }
    return false;
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);

    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) cin>>v[i];
    memset(visited,false,sizeof(visited));
    memset(vis,false,sizeof(vis));
    bool flag=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ch=v[i][j];
//            cout<<ch<<endl;
            if(!vis[i][j]){
//                cout<<i<<" "<<j<<endl;
                flag=dfs(i,j,-1,-1);
//                visited[v[i][j]]=true;
                if(flag) break;
//                memset(vis,false,sizeof(vis));
            }
        }
        if(flag) break;
    }
    if(flag) printf("Yes\n");
    else printf("No\n");
    return 0;
}
/*
Input
3 4
AAAA
ABCA
AAAA
Output
Yes
Input
3 4
AAAA
ABCA
AADA
Output
No
*/
