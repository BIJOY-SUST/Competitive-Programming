/*______________________________________________
 !                   BIJOY                      !
 !               CSE-25th Batch                 !
 !Shahjalal University of Science and Technology!
 !______________________________________________!
*/
#include<bits/stdc++.h>
//#define pi             3.14159265358979323846264338328
//#define pi             acos(-1)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define mx             1000001
//#define mod            1000000007
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
using namespace std;
bool flag[21];
//map<int,int>mp;
int main(){
//    freopen("01.txt","r",stdin);
//    freopen("02.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,a;
    while(scanf("%d %d",&i,&a)==2){
        if(i==0&&a==0) break;
        int ans=0,c=0;
        memset(flag,true,sizeof(flag));
        for(int j=1;j<=a;j++){
            int x,y;
            scanf("%d %d",&x,&y);
//            if(y>0){
//               if(mp[-y]==0) mp[y]++,c++;
//               else mp[-y]--;
//            }
            if(y<0){
                y=y*(-1);
                if(flag[y]){
                    flag[y]=false;
                    c++;
                }
//                else mp[-y]--,;
            }
        }
        printf("%d\n",i-c);
    }
    return 0;
}
