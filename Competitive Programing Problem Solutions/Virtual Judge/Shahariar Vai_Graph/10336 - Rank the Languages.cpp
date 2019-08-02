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
#define mx             10001
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
using namespace std;
const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};
int r,c;
char arr[mx][mx];
bool visited[mx][mx];
void DFS(int u,int v,char ch){
    visited[u][v]=true;
    for(int i=0;i<4;i++){
        int tx=u+fx[i];
        int ty=v+fy[i];
        if(valid(tx,ty)&&!visited[tx][ty]){
            if(arr[tx][ty]==ch) DFS(tx,ty,ch);
        }
    }
}
bool compare(const pair<char,int>&a,const pair<char,int>&b){
    //return a.second<b.second;
    return a.second==b.second? a.first<b.first:a.second>b.second;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        scanf("%d %d",&r,&c);
        for(int j=0;j<r;j++){
            scanf("%s",&arr[j]);
        }
        map<char,int>letter;
        memset(visited,false,sizeof(visited));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                char ch=arr[i][j];
                if(!visited[i][j]){
                    DFS(i,j,ch);
                    letter[ch]++;
                }
            }
        }
        vector<pair<char,int> >v(letter.begin(),letter.end());
        sort(v.begin(),v.end(),compare);
        printf("World #%d\n",tc);
        for(__typeof(v.begin()) it=v.begin();it!=v.end();it++){
            printf("%c: %d\n",it->first,it->second);
            //printf("%c: %d\n",(*it).first,(*it).second);
        }
        letter.clear();
        v.clear();
    }
    return 0;
}
