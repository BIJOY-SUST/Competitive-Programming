#include<stdio.h>
int main(){
    int x = 10;
    int *p;
    p=&x;

    printf("*p = %d\n", x);
    *p = 20;

    printf("%d\n", x);
    printf("%p\n", &x);
    printf("%p\n", p);
}

