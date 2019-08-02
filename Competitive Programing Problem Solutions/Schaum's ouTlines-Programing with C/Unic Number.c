#include<stdio.h>

int main() {
    int ara[100], n, i, j;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &ara[i]);
    }

    for(i = 0; i < n; i++) {
        for (j=0; j<i; j++){
            if (ara[i] == ara[j]){
                break;
            }
        }
        if (i == j){
            printf("%d ", ara[i]);
        }
    }
    return 0;
}
