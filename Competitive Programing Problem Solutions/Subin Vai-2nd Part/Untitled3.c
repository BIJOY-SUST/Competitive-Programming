#include<stdio.h>
int main(){
    int a = 10;
    int *p;
    p=&a;
    printf("*p = %d\n", *p);
    printf("%p\n", p);
}

