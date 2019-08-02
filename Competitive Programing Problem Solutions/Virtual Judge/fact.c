#include<stdio.h>
#include<string.h>
int main(){
    int n,fact,len;
    char k[25];

    scanf("%d",&n);
    scanf("%s",k);
    len = strlen(k);
    fact = 1;

    while(n>1){

            fact = fact*n;
            n = n-len;
    }
    printf("%d\n",fact);
}

/*if(n%2==0){

            fact = fact*n;
            n = n-len;
        }*/
