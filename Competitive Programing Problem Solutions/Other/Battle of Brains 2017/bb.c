#include<stdio.h>
int main(){
    int t;
    double x,ans,two;
    scanf("%d",&t);
    while(t--){
        ans=0;
        scanf("%lf",&x);
        while(x>=0.0000001){
            ans+=x;
            x=(double)x/sqrt(2);
        }
        printf("%.1lf\n",ans);
    }
    return 0;
}


