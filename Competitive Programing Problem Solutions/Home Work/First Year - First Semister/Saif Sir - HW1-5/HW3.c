#include<bits/stdc++.h>
using namespace std;
int main(){
    int i, j, k, n,s, nos = -1;
    scanf("%d",&n);
    for (i=(n+1)/2; i >0; i--) {
        for(j=1; j<=i; ++j)
        {
            printf("* ");
        }
        for (s = nos; s >= 1; s--) {
            printf("  ");
        }
        for (k = 1; k <=i; k++) {
            if (i ==(n+1)/2 && k == (n+1)/2) {
            continue;
            }
            printf("* ");
        }
        nos = nos + 2;
        printf("\n");
    }
    nos = nos-4;;
    for (i=2; i<=(n+1)/2; i++) {
        for(j=1; j<=i; ++j)
        {
            printf("* ");
        }
        for (s = nos; s>= 1; s--) {
            printf("  ");
        }
        for (k = 1; k <=i; k++) {
            if (i ==(n+1)/2 && k == (n+1)/2) {
            continue;
            }
            printf("* ");
        }
        nos = nos - 2;
        printf("\n");
    }
    return 0;
}
