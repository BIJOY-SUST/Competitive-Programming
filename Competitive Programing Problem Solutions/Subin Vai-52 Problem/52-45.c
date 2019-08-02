#include<stdio.h>

int main() {
    long long int T,i,j,k,N;
    long long int pascal[51][51];
    scanf("%lld", &T);
    while(T--){
        scanf("%lld", &N);
        pascal[1][0] = 1;
        pascal[2][0] = 1;
        pascal[2][1] = 1;
        for(i=1; i<=N; i++){
            if(i==1){
                printf("1\n");
            }
            else if(i==2){
                printf("1 1\n");
            }
            else{
                pascal[i][0] = 1;
                for(j=1; j<i-1; j++){
                    pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
                }
                pascal[i][j] = 1;
                for(j=0; j<i; j++){
                    printf("%lld " , pascal[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
