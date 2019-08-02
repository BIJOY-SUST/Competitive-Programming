#include<stdio.h>
#include<string.h>
#define NL '\n'
int main() {
    char letter[1000];
    int i=0, j;
    do {
        i++;
        j=i;
    } while((letter[i] = getchar()) != NL);

    i=0;
    do {
        putchar(toupper(letter[i]));
        i++;
    } while(i<j);
    return 0;
}

