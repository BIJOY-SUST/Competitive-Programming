#include<stdio.h>
int main() {
    int i, j, n = 7;
    for(i = n; i > 0; i--) {
        for(j = i; j > 0; j--) {
           printf("* ");
        }
        printf("\n");
    }
    for(i = 2; i <= n; i++) {
        for(j = 1; j <= i; j++) {
           printf("* ");
        }
        printf("\n");
    }

    return 0;
}


