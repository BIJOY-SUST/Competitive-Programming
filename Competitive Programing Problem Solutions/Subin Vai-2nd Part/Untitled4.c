#include<stdio.h>
int main(){

        double pi = 3.14159265358;
        int *ptr;
        ptr = &pi;
        printf("pi = %lf\n", pi);
        printf("%lf\n", *ptr);
}
