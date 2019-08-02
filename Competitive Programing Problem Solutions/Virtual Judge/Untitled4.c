#include<stdio.h>
int main(){

    int T,N,R,sum,i,n=1;
    scanf("%d",&T);
    while(T--){

        scanf("%d",&N);
        sum=0;
        for(i=0;i<N; i++){
            scanf("%d",&R);
            if(R>0){
            sum = sum+R;
            }
        }
        if(sum>0){
            printf("Case %d: %d\n",n,sum);
            n++;
    }
    }
    return 0;
}
