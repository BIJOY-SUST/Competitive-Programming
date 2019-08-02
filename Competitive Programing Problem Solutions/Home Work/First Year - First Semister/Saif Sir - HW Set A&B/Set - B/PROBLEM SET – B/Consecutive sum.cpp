#include<stdio.h>
int main()
{
    int n,i,a,b,sum;
    while(scanf("%d %d", &a, &b) == 2){

    sum=0;
    if(a<b){
        for(i=a; i<=b; i++){
            sum = sum + i;
        }
        printf("%d\n", sum);
    }
    else{
        for(i=b; i<=a; i++){
            sum = sum + i;
        }
        printf("%d\n", sum);
    }
    }
    return 0;
}

