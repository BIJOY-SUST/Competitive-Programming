/*______________________________________________
 !                   BIJOY                      !
 !               CSE-25th Batch                 !
 !Shahjalal University of Science and Technology!
 !______________________________________________!
*/
#include<bits/stdc++.h>
//#define PI             3.14159265358979323846264338328
//#define PI             acos(-1)
#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mx             101
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
using namespace std;
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
vector<string>s;
bool visited[mx][mx];
int r,c,ans;
void DFS(int u,int v){
    visited[u][v]=true;
    ans++;
    for(int i=0;i<8;i++){
        int tx=u+fx[i];
        int ty=v+fy[i];
        if(valid(tx,ty)&&!visited[tx][ty]){
            if(s[tx][ty]=='W'){

                DFS(tx,ty);
            }
        }
    }
}
int main(){
//    freopen("11.txt","r",stdin);
//    freopen("12.txt","w",stdout);
    int t;
    scanf("%d\n\n",&t);
    string ss;
    while(t--){
        s.clear();
        while(getline(cin,ss)){
            //if(ss=="") break;
            if(ss[0]!='W'&&ss[0]!='L') break;
            s.push_back(ss);
        }
        r=s.size();
        c=s[0].length();
        memset(visited,false,sizeof(visited));
        stringstream stt;
        int x,y;
        ans=0;
        stt.str(ss);
        stt>>x>>y;
        DFS(x-1,y-1);
        cout<<ans<<endl;
        while(getline(cin,ss)){
            if(ss.empty()) break;
            memset(visited,false,sizeof(visited));
            stringstream st;
            ans=0;
            st.str(ss);
            st>>x>>y;
            DFS(x-1,y-1);
            cout<<ans<<endl;
        }
        if(t>0) printf("\n");
    }
    return 0;
}
