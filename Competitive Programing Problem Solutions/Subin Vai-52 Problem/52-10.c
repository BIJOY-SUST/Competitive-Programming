#include<stdio.h>
int main() {
    int T,k;
    double n1,n2,q,r,p,b;
    scanf("%d", &T);
    for(k=1; k<=T; k++) {
        scanf("%lf %lf %lf", &n1, &n2, &b);
        p = 300 - b;
        q = 6*n2/p;
        r = (n1 - n2 + 1)*6/b;

        printf("%.2lf    %.2lf\n", q, r);

    }
    return 0;
}

