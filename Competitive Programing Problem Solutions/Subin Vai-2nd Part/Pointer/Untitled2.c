#include<stdio.h>
int sum_f(int n1,int n2){
    return n1+n2;
}
int sub_f(int n1,int n2){
    return n1-n2;
}
int main_f(int (*fnc)(int,int),int x1,int x2){
    return fnc(x1,x2);
}

int main(){
    int a=10,b=5;

    printf("%d\n",main_f(&sum_f,a,b));

    return 0;
}
