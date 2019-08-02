#include<stdio.h>
int main() {
    int n, count=0;
    float x, avarage, sum = 0;
    printf("How many numbers :");
    scanf("%d", &n);
    do {
        printf("x = ");
        scanf("%f", &x);
        sum = sum + x;
        count++;
    } while(count<n);
    avarage = sum/n;
    printf("Avarage is %f\n", avarage);
    return 0;
}

