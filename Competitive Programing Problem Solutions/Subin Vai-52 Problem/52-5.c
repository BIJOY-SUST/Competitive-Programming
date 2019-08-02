#include<stdio.h>
int main() {
    int T,i,N,j,k;
    scanf("%d", &T);
    for(k=1; k<=T; k++) {
        scanf("%d", &N);
        for(i=1; i<=N; i++) {
            for(j=1; j<=N; j++) {
                printf("*");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}


#include<stdio.h>
int main() {
    int T,i,j,k;
    scanf("%d", &T);
    int a[T];
    for(k=0; k<T; k++) {
        scanf("%d", &a[k]);
    }

    for(k=0; k<T; k++) {
        for(i=0; i<a[k]; i++) {
            for(j=0; j<a[k]; j++) {
                printf("*");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
