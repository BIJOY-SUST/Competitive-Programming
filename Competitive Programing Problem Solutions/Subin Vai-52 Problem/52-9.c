#include<stdio.h>
int main() {
    int T,i,k;
    double re;
    double dif;
    scanf("%d", &T);
    long int a[T];
    for(k=0; k<T; k++) {
        scanf("%d", &a[k]);
    }

    for(k=0; k<T; k++) {
        re = sqrt(a[k]);
        //if(dif = (ceil(re) - floor(re)) < 0.000001) { //It's Better than any other............
       if(ceil(re) == floor(re)) { //It's not better...............
            printf("YES");
        }
        else{
            printf("NO");
        }
            printf("\n");
    }
    return 0;
}
