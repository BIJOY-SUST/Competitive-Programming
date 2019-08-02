#include<stdio.h>
int binary(int m ) {
    int  bin = 0, i = 1, reminder;
    while(m != 0) {
        reminder = m%2;
        m = m/2;
        bin = bin + (reminder*i);
        i = i*10;
    }
    return bin;
}
int main() {
  long d, b;
    printf("Enter a Decimal number: ");
    scanf("%d", &d);
    b = binary(d);
    printf("Binary value is : %d\n", b);
    getch();
    return 0;
}
