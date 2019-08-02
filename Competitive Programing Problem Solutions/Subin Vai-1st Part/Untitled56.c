#include<stdio.h>
int main() {
    int i,space, row,  star;
    printf("Enter number of Row: ");
    scanf("%d", &row);
    for(i=row; i>=1; i--) {
        for(space=0; space<=row - i; space++) {
            printf(" ");
        }
        star = 0;
        while(star != (2*i - 1)) {
            printf("*");
            star++;
        }
        printf("\n");
    }
    for(i=2; i<=row; i++) {
        for(space=0; space<=row - i; space++) {
            printf(" ");
        }
        star = 0;
        while(star != (2*i - 1)) {
            printf("*");
            star++;
        }
        printf("\n");
    }
    return 0;
}
