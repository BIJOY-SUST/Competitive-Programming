#include<stdio.h>
int main(){
    int a,b;
    while(scanf("%d %d",&a,&b)){
        if(a%2==0&&b%2!=0){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
    }
    return 0;
}
