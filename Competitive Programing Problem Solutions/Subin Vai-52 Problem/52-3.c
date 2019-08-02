#include<stdio.h>
int main() {
    int i,j;
    for(i=1000,j=1; i<=1,j<=1000; i--,j++) {
        if(i!=0) {
            printf("%d  ", i);
        }
        if(j%5 == 0) {
            printf("\n");
        }
    }
    return 0;
}
