#include<stdio.h>
#define pi 3.1416
int main(){
    int i,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        double r,ans;
        scanf("%lf",&r);
        ans = 8*r*r-2*pi*r*r;
        printf("Case %d: %.2lf\n",i,ans);
    }
    return 0;
}
