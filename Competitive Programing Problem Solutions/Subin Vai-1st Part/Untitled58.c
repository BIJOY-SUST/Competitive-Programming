#include<stdio.h>
int main() {
    int i, raw, space;
    for(i=1; i<=10; ++i)
    {
        for(raw=1; raw<=i; raw++) {
            printf("* ");
        }
        for(space=i; space<=20-i-1; space++) {
            printf("  ");
        }
        for(raw=1; raw<=i; raw++) {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}
