/*______________________________________________
 !                   BIJOY                      !
 !               CSE-25th Batch                 !
 !Shahjalal University of Science and Technology!
 !______________________________________________!
*/
#include<bits/stdc++.h>
//#define PI             3.14159265358979323846264338328
//#define PI             acos(-1)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mx             101
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
using namespace std;
int arr[mx][mx];
int main(){
//    freopen("11.txt","r",stdin);
//    freopen("12.txt","w",stdout);
    int n;
    int tc=0;
    while(scanf("%d",&n)==1){
        if(n==0) break;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&arr[i][j]);
            }
        }
        printf("Case %d:",++tc);
        for(int i=0;i<n/2;i++){
            int ans=0;
            for(int j=i;j<n-1-i;j++){
                ans+=arr[i][j]+arr[j][n-1-i]+arr[n-1-i][n-1-j]+arr[n-1-j][i];
            }
            printf(" %d",ans);
        }
        if(n%2==1) printf(" %d\n",arr[n/2][n/2]);
        else printf("\n");
    }
    return 0;
}
