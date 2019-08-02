#include<stdio.h>
#include<stdlib.h>
int main(){

    int n,P,F;
    while(scanf("%d %d", &P, &F)==2){

        if(P == -1 && F == -1){
            break;
        }
        n = abs(P-F);
        if(n > 50){
            n= 100 - n;
        }
        printf("%d\n",n);
    }

    return 0;
}
