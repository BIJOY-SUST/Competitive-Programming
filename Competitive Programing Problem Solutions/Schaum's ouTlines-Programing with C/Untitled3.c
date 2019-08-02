#include<stdio.h>
int main() {
    int n, count=0;
    float x, avarage, sum = 0;
    printf("How many numbers :");
    scanf("%d", &n);
    while (count<n) {
        printf("x = ");
        scanf("%f", &x);
        sum = sum + x;
        count++;
    }
    avarage = sum/n;
    printf("Avarage is %f\n", avarage);
    return 0;
}
