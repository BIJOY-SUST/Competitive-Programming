#include<stdio.h>
int main() {
    int i, space, star;
    for(i=7; i>=1; i--) {
        for(space=0; space<=7 - i; space++) {
            printf(" ");
        }
        star = 0;
        while(star != i) {
            printf("*");
            star++;
        }
        printf("\n");
    }
    for(i=2; i<=7; i++) {
        for(space=0; space<=7 - i; space++) {
            printf(" ");
        }
        star = 0;
        while(star != i) {
            printf("*");
            star++;
        }
        printf("\n");
    }

}
