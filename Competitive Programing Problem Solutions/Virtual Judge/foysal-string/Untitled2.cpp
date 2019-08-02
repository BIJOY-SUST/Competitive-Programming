#include<stdio.h>
#include<string.h>

int main(){
    char s[123456];
    int d=1,l,i;

    while(gets(s)){
        l=strlen(s);
        for(i=0;i<l;i++){
        if(s[i]=='"'){
            if(d){
                printf("``");
                d=0;
            }
            else{
                printf("''");
                d=1;
            }
        }
        else{
            printf("%c",s[i]);
        }
    }
    printf("\n");
    }

    return 0;
}
