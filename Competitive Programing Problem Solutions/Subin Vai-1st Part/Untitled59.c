#include<stdio.h>
#include<string.h>
int main() {
    int i,j, len;
    char word[100], r_word[100];
    printf("Enter a word : ");
    scanf("%s", word);
    len = strlen(word);
    for(i=0, j=len -1; i<len; i++, j--) {
        r_word[i]  = word[j];
    }
    r_word[i] = '\0';
    printf("%s\n", r_word);
    if(0 == strcmp(word, r_word)) {
    printf("%s is a palindrome\n", word);
    }
    else {
        printf("%s is not a palidrome\n", word);
    }
    return 0;
}
