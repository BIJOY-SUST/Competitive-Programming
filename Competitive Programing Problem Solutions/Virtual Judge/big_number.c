#include<stdio.h>
#include<string.h>

int main(){
    int i,j,k,T;
    char a[100],b[100],c[100];
    scanf("%d",&T);
    getchar();
    for(i=1;i<=T;i++){
        gets(a);
        gets(b);
        if(strcmp(a,b)==0){
            printf("Case %d: Yes\n",i);
        }
        else{
            k=0;
            for(j=0;a[j];j++){
                if(isalpha(a[j])){
                    c[k++]=a[j];
                }
            }
            c[k] = '\0';
            if(strcmp(b,c)==0){
                printf("Case %d: Output Format Error\n",i);
            }
            else{
                printf("Case %d: Wrong Answer\n",i);
            }
        }
    }
    return 0;
}
