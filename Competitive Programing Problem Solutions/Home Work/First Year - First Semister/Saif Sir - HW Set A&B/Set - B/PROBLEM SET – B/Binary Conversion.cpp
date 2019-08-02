#include<stdio.h>
int main()
{
    long long int m, bin=0;
    int i = 1, reminder;
    while(scanf("%d", &m)){
        i = 1;
        bin = 0;
        while(m != 0){
        reminder = m%2;
        m = m/2;
        bin = bin + (reminder*i);
        i = i*10;

        }
        printf("%lld\n", bin);

        }
        return 0;
}
