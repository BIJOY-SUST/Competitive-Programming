#include<stdio.h>
#include<string.h>

int main(){
    int i,j,T,N,len;
    char a[100];
    char b[100];
    while(scanf("%d",&T)){
    for(i=1;i<=T;i++){
        scanf(" %[^\n]", a);
        scanf(" %[^\n]", b);
        //gets(a);
        //gets(b);
        len = strlen(a);
        for(j=0;j<len;j++){
            if(a[j]==' '){
                printf("Case %d: Output Format Error\n",i);
                break;
            }
            else if(a[j]!=b[j]){
                printf("Case %d: Wrong Answer\n",i);
                break;
            }
        }
        if(j==len){
            printf("Case %d: Yes\n",i);
        }
    }
    }
    return 0;
}
