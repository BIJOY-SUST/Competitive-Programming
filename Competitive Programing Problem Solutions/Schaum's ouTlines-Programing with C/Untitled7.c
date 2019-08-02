#include<stdio.h>
#include<string.h>
int main() {
    char line[80];
    int count;
    printf("Enter a line of text :\n");
    scanf("%[^\n]", &line);
    for(count=0; line[count]!='\0'; count++) {
                    if (((line[count] >= '0') && (line[count] <= '9')) ||
                        ((line[count] >= 'A') && (line[count] <= 'Z')) ||
                        ((line[count] >= 'a') && (line[count] <= 'z'))) {
            putchar(line[count] + 1);
        }
        else if (line[count] == '9') {
            putchar('0');
        }
        else if (line[count] == 'Z') {
            putchar('A');
        }
        else if (line[count] == 'z') {
            putchar('a');
        }
        else{
            putchar('.');
        }
    }
    return 0;
}
