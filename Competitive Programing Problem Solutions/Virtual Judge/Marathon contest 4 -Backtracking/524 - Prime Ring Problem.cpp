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
bool flag[25];
int ans[25]={1};
int n;
bool isprime(int p){
    for(int i=2;i<=sqrt(p);i++){
        if(p%i==0) return false;
    }
    return true;
}
void B_T(int len){
    if(len==n&&isprime(ans[n-1]+1)){
        printf("1");
        for(int i=1;i<n;i++) printf(" %d",ans[i]);
        printf("\n");
        return;
    }
    for(int i=2;i<=n;i++){
//        cout<<flag[i]<<" "<<ans[len-1]<<" "<<i<<" "<<isprime(i+ans[len-1])<<endl;
        if(!flag[i]&&isprime(i+ans[len-1])){
//        if(flag[i]) continue;
//        if(isprime(i+ans[len-1])){
            flag[i]=true;
            ans[len]=i;
            B_T(len+1);
            flag[i]=false;
        }
    }
}
int main(){
    int t=0;
    while(scanf("%d",&n)!=EOF){
        t++;
        if(t>1) printf("\n");
        memset(flag,false,sizeof(flag));
        printf("Case %d:\n",t);
        B_T(1);
    }
    return 0;
}
