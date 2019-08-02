#include <stdio.h>

int main(){
    int n,T, i;
    char str[1000000];
    scanf("%d", &T);
    for(i=1; i<=T; i++){

        scanf(" %[^\n]", str);
        printf("Case %d : Helllo %s\n", i, str);
    }
    return 0;
}

