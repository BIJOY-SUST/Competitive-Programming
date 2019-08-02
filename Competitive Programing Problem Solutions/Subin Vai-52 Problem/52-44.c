#include<stdio.h>

int main() {
    int T,i,j,k,N;
    int odd[21], even[21];
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        even[0]=1;
        even[1]=1;
        for(i=1; i<=N; i++){
            if(i==1){
                printf("1\n");
            }
            else if(i==2){
                printf("1 1\n");
            }
            else if(i%2==0){
                even[0]=1;
                for(j=1; j<i-1; j++){
                    even[j]=odd[j-1]+odd[j];
                }
                even[j]=1;
                for(j=0; j<i; j++){
                     printf("%d " , even[j]);
                }
                printf("\n");

            }
            else{
                odd[0]=1;
                for(j=1; j<i-1; j++){
                    odd[j]=even[j-1]+even[j];
                }
                odd[j]=1;
                for(j=0; j<i; j++){
                     printf("%d ", odd[j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
