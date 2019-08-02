#include<stdio.h>
int main()
{
    int num1, num2, value;
    char sign;
    printf("Plese enter a number:");
    scanf("%d", &num1);
    printf("Plese enter another number:");
    scanf("%d", &num2);
    value=num1+num2;
    sign='+';
    printf("%d %c %d = %d\n", num1, sign, num2, value);
    value=num1-num2;
    sign='-';
    printf("%d %c %d = %d\n", num1, sign, num2,value);
    value=num1*num2;
    sign='*';
    printf("%d %C %d = %d\n", num1, sign, num2, value);
    value=num1/num2;
    sign='/';
    printf("%d %c %d = %d\n", num1, sign, num2, value);
    return 0;
}
