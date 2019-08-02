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
const int fx[]={+0,+0,+1,-1,+1,-1};
const int fy[]={-1,+1,+0,+0,+1,-1};
char arr[201][201];
int n;
//int r=n,c=n;
bool flag;
bool visited[201][201];
void DFS(int u,int v){
    //cout<<u<<endl;
    if(v==n-1){
        //cout<<"BIJOY"<<endl;
        flag=true;
        return;
    }
    for(int i=0;i<6;i++){
        int tx=u+fx[i];
        int ty=v+fy[i];
        if(valid(tx,ty)&&!visited[tx][ty]){
            if(arr[tx][ty]=='w'){
                visited[tx][ty]=true;
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
    while(scanf("%d",&n)&&n!=0){
        flag=false;
        memset(visited,false,sizeof(visited));
        //memset(arr,0,sizeof(arr));
        for(int i=0;i<n;i++){
            scanf("%s",&arr[i]);
        }
        for(int i=0;i<n;i++){
            if(arr[i][0]=='w'&&!visited[i][0]){
                //cout<<"BIJOY"<<endl;
                //cout<<0<<i<<endl;
                DFS(i,0);
            }
        }
        if(flag) printf("%d W\n",++t);
        else printf("%d B\n",++t);
    }
    return 0;
}
