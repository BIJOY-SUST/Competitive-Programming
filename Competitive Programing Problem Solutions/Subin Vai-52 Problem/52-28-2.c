#include<stdio.h>
#include<string.h>
int main() {
    int T,k,n,i,j,m,flag=0;
    int ara[21];
    int ara2[21];
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(k=0; k<n; k++) {
            scanf("%d", &ara[k]);
        }
        for(i=0,j=0; i<n; i++) {
            ara2[j]=ara[i];
            j++;
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
            if(ara2[i] != ara[i]){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            printf("YES\n");
        }
        else if(flag == 1){
            printf("NO\n");
        }
    }
    return 0;
}

