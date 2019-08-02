#include<stdio.h>
int main(){

    int T,count=0;
    long long n,i;

    scanf("%d", &T);
    for(i=0;i<T/2;i++){
        printf("denate  ");
        scanf("%lld",&n);
        count+=n;
        printf("report  ");
        printf("%d\n",count);
    }
    return 0;
}
