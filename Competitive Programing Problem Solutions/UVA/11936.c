#include<stdio.h>
int main(){

    int i,j,N,a,b,c;
    scanf("%d", &N);
    while(N--){
        scanf("%d %d %d",&a, &b, &c);
        if(a+b>c){
            printf("OK\n");
        }
        else{
            printf("Wrong!!\n");
        }
    }
    return 0;
}
