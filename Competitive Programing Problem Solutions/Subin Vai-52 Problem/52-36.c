#include<stdio.h>
#include<string.h>
int main(){
    char str1[100], str2[100];
    gets(str1);
    gets(str2);
    if(strcmp (str1,str2) == 1){
        printf("Greater\n");
    }
    else if(strcmp (str1,str2) ==-1){
        printf("Lesser\n");
    }
    else{
        printf("Equal\n");
    }
    return 0;
}
