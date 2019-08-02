#include<bits/stdc++.h>
#define valid(tx,ty) tx>=0&&tx<r&&ty>=0&&ty<c
using namespace std;
int fx[]={+1,-1,+0,+0};
int fy[]={+0,+0,+1,-1};
int r,c;
char arr[1010][1010];
bool visited[1010][1010];
int aaa[1010][1010];
int BFS(int x,int y){
    queue<pair<int,int> >q;
    q.push(make_pair(x,y));
    visited[x][y]=true;
    int d=0;
    while(!q.empty()){
        //cout<<"jghg"<<endl;
        pair<int,int>p;
        p=q.front();
        q.pop();
        for(int i=0;i<4;i++){
                //cout<<"girehg"<<endl;
            int tx=p.first+fx[i];
            int ty=p.second+fy[i];
            //cout<<r<<" "<<c<<endl;
            if(arr[tx][ty]=='.'&&valid(tx,ty)&&!visited[tx][ty]){
                visited[tx][ty]=true;
                aaa[tx][ty]=aaa[p.first][p.second]+1;
                if(aaa[tx][ty]>d) d=aaa[tx][ty];
                //cout<<tx<<" "<<ty<<endl;
               // c++;
                q.push(make_pair(tx,ty));
            }
        }
    }
    return d;
}
int is_BFS(){
    memset(visited,false,sizeof(visited));
    memset(aaa,0,sizeof(aaa));
    int ans=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j]=='.'&&!visited[i][j]){
                //visited[i][j]=1;
                arr[i][j]=0;
                int hh=BFS(i,j);
                //return hh;
                //cout<<hh<<endl;
                if(hh>ans) ans=hh;
            }
        }
    }
    return ans;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        memset(arr,0,sizeof(arr));
        scanf("%d %d",&c,&r);
        for(int j=0;j<r;j++){
            scanf("%s",&arr[j]);
        }
        int k,x=-1,y=-1;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(arr[i][j]=='.'){
                    x=i,y=j;
                    goto k;
                }
            }
        }
        k:

        printf("Maximum rope length is %d.\n",k);
//        for(int j=0;j<r;j++)
//        for(int h=0;h<c;h++)
//            printf("%d",aaa[j][h]);
    }
}
