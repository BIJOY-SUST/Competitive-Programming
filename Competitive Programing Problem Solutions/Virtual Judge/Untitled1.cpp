#include<stdio.h>
#include<string.h>

int main(){
    int len,i,k,n;
    char a[100000];
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf(" %[^\n]",a);
        len = strlen(a);
        if(len<=10){
            printf("%s\n",a);
        }
        else if(len>10){
            k = len - 2;
            printf("%c%d%C\n",a[0],k,a[len-1]);
        }
    }

    return 0;
}
