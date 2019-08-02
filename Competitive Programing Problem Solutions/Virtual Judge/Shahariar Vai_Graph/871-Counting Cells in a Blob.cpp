/*______________________________________________
 !                   BIJOY                      !
 !               CSE-25th Batch                 !
 !Shahjalal University of Science and Technology!
 !______________________________________________!
*/
#include<bits/stdc++.h>
#define valid(tx,ty) tx>=0&&tx<r&&ty>=0&&ty<c
using namespace std;
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
vector<string>s;
bool visited[26][26];
int r,c,dis[26][26];
int BFS(int x,int y){
    queue<pair<int,int> >q;
    q.push(make_pair(x,y));
    visited[x][y]=true;
    //dis[x][y]=1;
    int ans=1;
    while(!q.empty()){
        pair<int,int>p;
        p=q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int tx=p.first + fx[i];
            int ty=p.second+ fy[i];
            if(valid(tx,ty)&&!visited[tx][ty]){
                if(s[tx][ty]=='1'){
                    q.push(make_pair(tx,ty));
                    visited[tx][ty]=true;
                    ans++;
                }
                //dis[tx][ty]=dis[p.first][p.second]+1;
                //if(dis[tx][ty]>ans) ans=dis[tx][ty];
            }
        }
    }
    return ans;
}
int main(){
//    freopen("11.txt","r",stdin);
//    freopen("12.txt","w",stdout);
    int t,New=0;;
    scanf("%d\n\n",&t);
    string ss;
    while(t--){
        s.clear();
        while(getline(cin,ss)){
            if(ss=="") break;
            s.push_back(ss);
        }
        r=s.size();
        c=s[0].length();
        memset(visited,false,sizeof(visited));
        memset(dis,0,sizeof(dis));
        int dd,ans=0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                //cout<<ans<<endl;
                char ch=s[i][j];
                if(ch=='1'&&!visited[i][j]){
                    dd=BFS(i,j);
                    if(dd>ans) ans=dd;
                }
            }
        }
        //cout<<ans<<endl;
        if(New) printf("\n");
        New=1;
        printf("%d\n",ans);
    }
    return 0;
}
