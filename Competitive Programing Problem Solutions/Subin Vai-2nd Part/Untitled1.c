#include<stdio.h>
int main(){
    char c = 'A', v = 'B';
    int a = 10, n = 25;
    printf("%c,\t", c);
    printf("%p\n", &c);
    printf("%c,\t", v);
    printf("%p\n", &v);
    printf("%d,\t", a);
    printf("%p\n", &a);
    printf("%d,\t", n);
    printf("%p\n", &n);
}
