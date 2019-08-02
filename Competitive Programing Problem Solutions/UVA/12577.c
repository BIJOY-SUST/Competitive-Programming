#include<stdio.h>
#include<string.h>

int main(){
    char str[100];
    int i=1;

    while(1){
        gets(str);

        if(strcmp(str,"Hajj")==0){
            printf("Case %d: Hajj-e-Akbar\n", i);
            i++;
        }
        else if(strcmp(str ,"Umrah")==0){
            printf("Case %d: Hajj-e-Asghar\n", i);
            i++;
        }
        else if(strcmp(str,"*")==0) {
            return 0;
        }
    }
    return 0;
}
