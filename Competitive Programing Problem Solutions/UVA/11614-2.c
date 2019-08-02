#include<stdio.h>
#include<math.h>
int main(){

    int T,count;
    long long n,i;

    scanf("%d", &T);
    while(T--){

        scanf("%lld",&n);
        count = (sqrt(1+8*n)-1)/2;
        printf("%d\n",count);
    }
    return 0;
}
