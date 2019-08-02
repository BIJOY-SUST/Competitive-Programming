#include<stdio.h>
int main(){
    int a,b,n;
    printf("Enter : ");
    scanf("%d %d", &a, &b);
    while(b!=0){
        n=a%b;
        a=b;
        b=n;

    }
    printf("gcd is %d", a);
    return 0;
}
