#include<stdio.h>
#include<math.h>

int main(){
    long int T,i,s,j,N;
    while(scanf("%ld", &N) && N!=0){
        for(i=1; i<N; i++){
            if(N%i == 0){
            printf("%ld, ",i);
            }
        }
        printf("%ld\n", i);
    }
    return 0;
}
