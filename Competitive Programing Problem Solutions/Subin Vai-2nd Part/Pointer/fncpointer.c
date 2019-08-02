#include<stdio.h>
int add(int n1, int n2){
    return n1+n2;
}
int sub(int n1, int n2){
    return n1-n2;
}

int main(){
    int (*fnc)(int,int);
    int a=10,b=5;
    fnc = &add;
    printf("Result : %d\n",fnc(a,b));
    fnc = &sub;
    printf("Result : %d\n",fnc(a,b));

    return 0;
}

