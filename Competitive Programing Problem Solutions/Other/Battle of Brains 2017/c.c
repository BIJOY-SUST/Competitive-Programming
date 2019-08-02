#include<stdio.h>
int main(){
    int t;
    double x,ans,two;
    scanf("%d",&t);
    while(t--){
        scanf("%lf",&x);
        ans=x*x/2.0;
        printf("%.2lf\n",ans);
    }
    return 0;
}


