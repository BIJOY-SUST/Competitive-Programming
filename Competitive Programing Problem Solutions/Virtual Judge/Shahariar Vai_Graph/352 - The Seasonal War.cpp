/*______________________________________________
 !                   BIJOY                      !
 !               CSE-25th Batch                 !
 !Shahjalal University of Science and Technology!
 !______________________________________________!
*/
#include<bits/stdc++.h>
//#define PI            3.14159265358979323846264338328
//#define PI            acos(-1)
#define valid(tx,ty)  tx>=0&&tx<n&&ty>=0&&ty<n
//#define MX            1000001
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
using namespace std;
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
char arr[26][26];
int n;
//int r=n,c=n;
//bool flag;
bool visited[26][26];
void DFS(int u,int v){
    //cout<<u<<endl;
//    if(v==n-1){
//        //cout<<"BIJOY"<<endl;
//        flag=true;
//        return;
//    }
    visited[u][v]=true;
    for(int i=0;i<8;i++){
        int tx=u+fx[i];
        int ty=v+fy[i];
        if(valid(tx,ty)&&!visited[tx][ty]){
            if(arr[tx][ty]=='1'){

                DFS(tx,ty);
            }
        }
    }
    return;
}
int main(){
//    freopen("11.txt","r",stdin);
//    freopen("12.txt","w",stdout);
    int t=0;
    while(scanf("%d",&n)==1){
        //flag=false;
        memset(visited,false,sizeof(visited));
        //memset(arr,0,sizeof(arr));
        for(int i=0;i<n;i++){
            scanf("%s",&arr[i]);
        }
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]=='1'&&!visited[i][j]){
                    //cout<<"BIJOY"<<endl;
                    //cout<<0<<i<<endl;
                    DFS(i,j);
                    c++;
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n",++t,c);
    }
    return 0;
}

