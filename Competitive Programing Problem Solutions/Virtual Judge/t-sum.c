#include<stdio.h>
int main(){
    int N,i,sum;
    scanf("%d",&N);
    sum = 0;
    if(N>1){
        for(i=1;i<=N;i++){
            sum = sum + i;
        }
    }
    else{
        //N=abs(N);
        for(i=1;i>=N;i--){
            sum = sum + i;
        }
    }
    printf("%d\n",sum);
    return 0;
}

