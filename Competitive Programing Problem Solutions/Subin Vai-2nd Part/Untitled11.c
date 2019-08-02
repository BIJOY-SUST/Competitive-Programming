#include<stdio.h>
int main(){
    char s[] = "Bangladesh";
    char *p;

    p = s;
    printf("Name of our counter : %s\n", s);
    printf("Address of s:%s %p\n",p, p);
    return 0;
}
