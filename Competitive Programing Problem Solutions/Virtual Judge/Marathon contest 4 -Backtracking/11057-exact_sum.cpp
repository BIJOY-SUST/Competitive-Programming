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
vector<int>v;
int main(){
    int N,M,x,y,k;
    while(scanf("%d",&N)==1){
        int differ=2000001;
        for(int i=0;i<N;i++){
            scanf("%d",&k);
            v.push_back(k);
        }
        scanf("%d",&M);
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(v[i]+v[j]==M&&i!=j){
                    if(v[i]>v[j]){
                        if((v[i]-v[j])<differ){
                            x=v[j];
                            y=v[i];
                            differ=v[i]-v[j];
                        }
                    }
                    else{
                        if((v[j]-v[i])<differ){
                            x=v[i];
                            y=v[j];
                            differ=v[j]-v[i];
                        }
                    }
                }
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n",x,y);
        v.clear();
    }
    return 0;
}
