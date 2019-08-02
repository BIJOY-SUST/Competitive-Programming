#include<stdio.h>
#define Swap(a,b){\
    a ^= b;\
    b ^= a;\
    a ^= b;\
}
int main(){
    int m = 83, n= 323;

    printf("m = %d  n = %d\n",m,n);
    Swap(m,n);
    printf("m = %d  n = %d\n",m,n);
}
