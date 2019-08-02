   #include<stdio.h>
int main(){
    int y,x = 10;
    int *p,*q;


    p=&x;
    q=&y;
    *p=15;
    *q=20;


    printf("value of x=%d\n", x);
    printf("value of x=%d\n", y);
    printf("value of x=%d\n", *p);
    printf("value of x=%d\n", *q);

}
