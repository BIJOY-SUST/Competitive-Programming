/*______________________________________________
 !                   BIJOY                      !
 !               CSE-25th Batch                 !
 !Shahjalal University of Science and Technology!
 !______________________________________________!
*/
#include<bits/stdc++.h>
//#define PI             3.14159265358979323846264338328
//#define PI             acos(-1)
#define valid(tx,ty)   tx>=0&&tx<n&&ty>=0&&ty<n
#define mx             101
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
using namespace std;
const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};
int n;
char arr[mx][mx];
bool visited[mx][mx];
void DFS(int u,int v){
    visited[u][v]=true;
    for(int i=0;i<4;i++){
        int tx=u+fx[i];
        int ty=v+fy[i];
        if(valid(tx,ty)&&!visited[tx][ty]){
            if(arr[tx][ty]!='.') DFS(tx,ty);
        }
    }
}
//bool compare(const pair<char,int>&a,const pair<char,int>&b){
//    //return a.second<b.second;
//    return a.second==b.second? a.first<b.first:a.second>b.second;
//}
int main(){
//    freopen("11.txt","r",stdin);
//    freopen("12.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        scanf("%d",&n);
        for(int j=0;j<n;j++){
            scanf("%s",&arr[j]);
        }
//        map<char,int>letter;
        memset(visited,false,sizeof(visited));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]=='x'&&!visited[i][j]){
                    ans++;
                    DFS(i,j);
                }
            }
        }
        printf("Case %d: %d\n",tc,ans);
//        vector<pair<char,int> >v(letter.begin(),letter.end());
//        sort(v.begin(),v.end(),compare);
//        printf("World #%d\n",tc);
//        for(__typeof(v.begin()) it=v.begin();it!=v.end();it++){
//            printf("%c: %d\n",it->first,it->second);
//            //printf("%c: %d\n",(*it).first,(*it).second);
//        }
//        letter.clear();
//        v.clear();
    }
    return 0;
}

