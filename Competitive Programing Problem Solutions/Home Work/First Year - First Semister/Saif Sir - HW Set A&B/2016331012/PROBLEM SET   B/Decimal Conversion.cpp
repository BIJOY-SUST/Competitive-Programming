#include<stdio.h>
#include<string.h>
#include<math.h>
int main() {
    char bin[1000000];
    int i, lenght, power, decimal;
    while(scanf("%s", &bin)){

        decimal = 0;
        lenght = strlen(bin);
        power = lenght - 1;
        for(i = 0; i <lenght; i++) {
            decimal += (bin[i] - '0') * pow (2 , power);
            power--;
        }
        printf("%d\n", decimal);
    }
    return 0;
}
