#include<stdio.h>
int main() {
    char x;
    printf("Incert a Character:");
    scanf("%c", &x);
    if(x>='a' && x<='z') {
        printf("The character is a lower case letter.\n");
    }
    else if(x>='A' && x<='Z') {
        printf("The character is a upper case letter.\n");
    }
    else if(x>='0' || x<='0') {
        printf("The character is a digit.\n");
    }
    return 0;
}
