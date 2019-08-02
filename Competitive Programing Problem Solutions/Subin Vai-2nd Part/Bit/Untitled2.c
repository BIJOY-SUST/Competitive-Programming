#include<stdio.h>
int main(){
    int n, count=0;
    scanf("%d",&n);
    while(n){
        if(n&1){
            count++;
        }
        n=n>>1;
    }
    printf("Number of 1: %d\n",count);

    return 0;
}
