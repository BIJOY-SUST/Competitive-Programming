#include<stdio.h>
int main() {
    int ara1[] = {3,1,5,2,4};
    int ara2[5];
    int i, j, minimum, n;
    for (i=0; i<5; i++) {
        minimum = 1000;
        for(j=0; j<5; j++) {
            if(ara1[j]<minimum) {
                minimum = ara1[j];
                n = j;
            }
        }
        ara1[n] = 100;
        ara2[i] = minimum;
    }
    for(i=0; i<5; i++) {
        printf("%d ", ara2[i]);
    }
    return 0;
}
