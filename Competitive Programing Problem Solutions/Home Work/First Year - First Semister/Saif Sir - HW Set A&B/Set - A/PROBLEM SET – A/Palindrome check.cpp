#include<stdio.h>
#include<string.h>
int main() {
    int i,T,j, len,count = 1;
    char word[100], r_word[100];
    scanf("%d", &T);
    while(T--){
    scanf("%s", word);
    len = strlen(word);
    for(i=0, j=len -1; i<len; i++, j--) {
        r_word[i]  = word[j];
    }
    r_word[i] = '\0';
    if(0 == strcmp(word, r_word)) {
    printf("Case %d: Yes\n", count);
    count++;
    }
    else {
        printf("Case %d: No\n", count);
        count++;
    }
    }
    return 0;
}
