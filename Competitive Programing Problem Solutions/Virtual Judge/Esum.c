#include<stdio.h>
int main(){
long N,M,ara[100000],div,i,j,x,y;
while(scanf("%ld",&N)==1){
    div=2000000;
    for(i=1;i<=N;i++)
    scanf("%ld",&ara[i]);
    scanf("%ld",&M);
    for(i=1;i<=N;i++){
        for(j=1;j<=N;j++){
            if((ara[i]+ara[j])==M && i!=j){
                if(ara[i]>ara[j]){
                    if((ara[i]-ara[j])<div){
                        x=ara[j];
                        y=ara[i];
                        div=ara[i]-ara[j];
                        }
                    }
                else{
                    if((ara[j]-ara[i])<div){
                        x=ara[i];
                        y=ara[j];
                        div=ara[j]-ara[i];
                    }
                }
            }
        }
    }
    printf("Peter should buy books whose prices are %ld and %ld.\n\n",x,y);
    }
    return 0;
}
