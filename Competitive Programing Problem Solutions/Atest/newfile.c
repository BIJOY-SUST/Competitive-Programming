#include<stdio.h>


int hello(int a){

    printf("Hello World\n");

    a++;
    printf("%d\n",a);
    return a;

}

int main(){


    int a;
    scanf("%d",&a);
    int ans;

    ans = hello(a);


    printf("Answer = %d \n",ans);


}
