/*______________________________________________
 !                   BIJOY                      !
 !               CSE-25th Batch                 !
 !Shahjalal University of Science and Technology!
 !______________________________________________!
*/
#include<bits/stdc++.h>
//#define PI             3.14159265358979323846264338328
//#define PI             acos(-1)
//#define mod            1000000007
#define valid(tx,ty)   tx>=0&&tx<n&&ty>=0&&ty<n
#define mx             21
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
using namespace std;
const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};
char arr[mx][mx];
bool visited[mx][mx];
int dis[mx][mx];
int ans;
int n;
int BFS(char ch,int u,int v){
    queue<pair<int,int> >q;
    memset(visited,false,sizeof(visited));
    memset(dis,0,sizeof(dis));
    q.push(make_pair(u,v));
    visited[u][v]=true;
    while(!q.empty()){
        pair<int,int>p;
        p=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int tx=p.first+fx[i];
            int ty=p.second+fy[i];
            if(valid(tx,ty)&&!visited[tx][ty]){
                if(arr[tx][ty]!='#'&&arr[tx][ty]<=ch+1){
                    visited[tx][ty]=true;
                    q.push(make_pair(tx,ty));
                    dis[tx][ty]=dis[p.first][p.second]+1;
                    if(arr[tx][ty]==ch+1) return dis[tx][ty];
                }
            }
        }
    }
    return -1;
}
int main(){
//    freopen("11.txt","r",stdin);
//    freopen("12.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%s",&arr[i]);
        }
        memset(visited,false,sizeof(visited));
        int c_char=0,ans=0;
        pair<int,int>p[27];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isalpha(arr[i][j])){
                    p[arr[i][j]-'A'].first=i;
                    p[arr[i][j]-'A'].second=j;
                    c_char++;
                }
            }
        }
        bool flag=true;
        for(int i=0;i<c_char-1;i++){
            int tem_ans=BFS('A'+i,p[i].first,p[i].second);
            if(tem_ans==-1){
                flag=false;
                break;
            }
            ans+=tem_ans;
        }
        if(flag) printf("Case %d: %d\n",tc,ans);
        else printf("Case %d: Impossible\n",tc);
    }
    return 0;
}

