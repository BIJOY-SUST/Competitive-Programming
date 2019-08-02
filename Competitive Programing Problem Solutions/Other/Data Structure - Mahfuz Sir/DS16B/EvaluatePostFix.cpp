#include<stdio.h>
#include<ctype.h>
#include<math.h>
int STK[100], TOP = -1;
void push(int p)
{
    TOP++;
    STK[TOP] = p;
}
int pop()
{
    int p = STK[TOP];
    TOP--;
    return p;
}
int main()
{
    int i;
    char postFix[100];
    gets(postFix);
    for(i=0;postFix[i]!='\0';i++)
    {
        if(isdigit(postFix[i]))
        {
            //operand
            //printf("digit! Push %d\n", postFix[i] - '0');
            push(postFix[i]-'0');
        }
        else
        {
            //operator
            int b = pop();
            int a = pop();
            int r;
            //printf("%c found\n", postFix[i]);
            //printf("calculating %d %c %d\n", a, postFix[i], b);
            switch(postFix[i])
            {
                case '+':
                        r = a + b;
                        break;
                case '-':
                        r = a - b;
                        break;
                case '*':
                        r = a * b;
                        break;
                case '/':
                        r = a / b;
                        break;
                case '^':
                        r = pow(a, b);
                        break;
                default:
                        r = 0;
            }
            //printf("Push %d\n", r);
            push(r);
        }
    }
    printf("Result: %d\n", pop());

    return 0;
}
