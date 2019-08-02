#include<stdio.h>
int main(){
    long int i,j,m,n,N,ara[100000],M,k;
    while(scanf("%ld",&N)){
    k=2000000;
    for(m=0;m<N;m++){
        scanf("%ld",&ara[m]);
    }
    scanf("%ld",&M);
    for (m = 0 ; m < N-1; m++){
        for(n = 0 ; n < N-1; n++){
            if (ara[m]+ara[n]==M && m!=n){
                if(ara[m]>ara[n]){
                    if(ara[m]-ara[n]<k){
                        i=ara[n];
                        j=ara[m];
                        k=ara[m]-ara[n];
                    }
                }
                else{
                    if(ara[n]-ara[m]<k){
                        i=ara[m];
                        j=ara[n];
                        k=ara[n]-ara[m];
                    }
                }
            }
        }
    }
    printf("Peter should buy books whose prices are %ld and %ld.\n\n",i,j);
    }
    return 0;
}
