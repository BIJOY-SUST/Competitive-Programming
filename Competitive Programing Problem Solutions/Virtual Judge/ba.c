#include<stdio.h>

int main(){
    int s,i,t,N,K,P;
    while(scanf("%d",&t)==1){
        for(i=1;i<=t;i++){
            scanf("%d%d%d",&N,&K,&P);
            s=K+P;
            while(s>N){
                s=s-N;
            }
            printf("Case %d: %d\n",i,s);
        }
    }
    return 0;
}

