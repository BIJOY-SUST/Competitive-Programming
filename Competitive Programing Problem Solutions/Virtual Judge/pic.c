#include<stdio.h>
#include<string.h>
int main() {
    int T,k,n,i,j,m,flag=1,sum1,sum2;
    int ara[21];
    int ara2[21];
    scanf("%d", &T);
    while(T--) {
        printf("\n");
        scanf("%d", &n);
        sum1=0;
        sum2=0;
        for(k=0; k<n; k++) {
            scanf("%d", &ara[k]);
        }
        for(i=0; i<n-1; i++) {
            for(j=0; j<n-i-1; j++){
                if(ara[j]>ara[j+1]){
                    m = ara[j];
                    ara[j] = ara[j+1];
                    ara[j+1] = m;
                }
            }
        }
        for(i=0,j=0; i<n; i++) {
            ara2[i]=ara[j];
            //printf("%d\n", ara2[i]);
            j++;
        }
        if(n==3){
            sum1=ara2[0]+ara2[1];
            sum2=ara2[2];
        }
        else if(n==4){
            sum1=ara2[0]+ara2[3];
            sum2=ara2[1]+ara2[2];
        }
        else{
            for(i=0; i<n; i=i+2){
            sum1=sum1+ara2[i];
            }
            for(i=1; i<n; i=i+2){
            sum2=sum2+ara2[i];
            }
        }
        if(sum1<sum2){
            printf("Case %d: %d %d\n",flag,sum1,sum2);
            flag++;
        }
        else{
            printf("Case %d: %d %d\n",flag,sum2,sum1);
            flag++;
        }

    }
    return 0;
}
