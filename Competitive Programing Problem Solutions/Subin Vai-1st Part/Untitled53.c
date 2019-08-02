#include<stdio.h>
#include<string.h>
#include<math.h>
int main() {
    char bin[1000000];
    int i, lenght, power, decimal = 0;
    printf("Enter a Binary number: ");
    scanf("%s", &bin);
    lenght = strlen(bin);
    power = lenght - 1;
    for(i = 0; i <lenght; i++) {
        decimal += (bin[i] - '0') * pow (2 , power);
        power--;
    }
    printf("Decimal Value is : %d\n", decimal);
    return 0;
}
