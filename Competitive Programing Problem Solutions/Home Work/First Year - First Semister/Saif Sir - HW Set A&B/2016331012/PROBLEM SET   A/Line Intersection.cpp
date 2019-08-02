#include <stdio.h>

int main(){
    int T, count = 1, a1, b1, c1, a2, b2, c2;
    double x, y, dev;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d", &a1, &b1, &c1);
        scanf("%d %d %d", &a2, &b2, &c2);
        dev = a1*b2 - a2*b1;
        if(dev == 0.0){
            printf("Undefined\n");
        }
        else{
            x = (b2*c1 - b1*c2)/dev;
            y = (a1*c2 - a2*c1)/dev;
            printf("Case %d: x = %.3lf, y = %.3lf\n", count, x, y);
            count++;
        }

    }
    return 0;
}
