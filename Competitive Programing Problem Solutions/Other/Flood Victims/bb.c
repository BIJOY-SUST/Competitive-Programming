#include<stdio.h>
int main(){
    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        double L,W,D,ans;
        scanf("%lf %lf %lf",&L,&W,&D);
        ans=((W-D)*L)/2;
        printf("Case %d: %.2lf\n",i,ans);
    }
    return 0;
}


