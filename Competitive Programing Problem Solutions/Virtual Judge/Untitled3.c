#include<stdio.h>
int main(){

    int T,a,b,i=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&a,&b);
        printf("Case %d: %d\n",i,a+b);
        i++;
    }
    return 0;
}
