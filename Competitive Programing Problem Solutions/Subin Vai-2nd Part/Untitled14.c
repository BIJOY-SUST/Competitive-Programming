#include<stdio.h>
int main(){

    char c = 'A';
    char *p, **q;
    p = &c;
    q = &p;

    printf("Value  of c : %c %p\n", c,c);
    printf("Value  of c : %c %p\n", *p,p);
    printf("Value  of c : %c %p\n", **q,q);
}
