#include<stdio.h>
void plus_1(int a){
    a=a+10;
    return a;
}
void plus_2(int *a){
    *a = (*a) + 10;
}
int main(){
    int a;
    a=5;

    plus_1(a);
    printf("a = %d\n",a);

    plus_2(&a);
    printf("a = %d\n",a);

    return 0;
}
