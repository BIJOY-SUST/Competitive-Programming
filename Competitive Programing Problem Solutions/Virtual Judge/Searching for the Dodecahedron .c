#include <stdio.h>

int main(){
    int n,i,m;

    scanf("%d",&n);
    m = 2*n - 1;
    printf("%d\n",m);

    for(i = 1;i <= n;i++){
        printf("%d ",i);
    }
    for(i = n;i >= 2;i--){
        printf("%d ",i);
    }
    return 0;
}
