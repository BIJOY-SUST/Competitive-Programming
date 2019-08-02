#include<stdio.h>
int main() {
    int T, i;
    char n[101];
    scanf("%d", &T);
    for(i=1; i<=T; i++) {
        scanf("%s", &n);//printf("%s", n[0]);

        if(n[i] % 2 == 0) {
            printf("even\n");
        }
        else{
            printf("odd\n");
        }
    }
    return 0;
}
