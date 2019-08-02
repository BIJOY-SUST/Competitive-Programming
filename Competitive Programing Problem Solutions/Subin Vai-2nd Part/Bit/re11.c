#include<stdio.h>
int main(){
    int ara[] = {4,2,3,4,1,2,3};
    int result,i,n=7;

    result = ara[0];
    for(i=1;i<n;i++){
        result = result^ara[i];
    }
printf("%d\n",result);
}
