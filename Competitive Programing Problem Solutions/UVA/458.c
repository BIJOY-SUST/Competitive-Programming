#include<stdio.h>
#include<string.h>
int main(){

        int i,len;
        char str[1000];
        while(gets(str)){
        len = strlen(str);
        for(i=0; i<len; i++){
            printf("%c",str[i]-7);
        }
        printf("\n");
        }
        return 0;
}
