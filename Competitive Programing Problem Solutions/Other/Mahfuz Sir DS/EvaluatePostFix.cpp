#include<stdio.h>
#include<math.h>
#include<ctype.h>
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
            push(postFix[i]-'0');
        }
        else
        {
            //operator
            int a = pop();
            int b = pop();
            int r;
            switch(postFix[i])
            {
                case '+':
                        r = b+a;
                        break;
                case '-':
                        r = b-a;
                        break;
                case '*':
                        r = b*a;
                        break;
                case '/':
                        r = b/a;
                        break;
                case '%':
                        r = b%a;
                        break;
                case '^':
                        r = pow(b, a);
                        break;
                default:
                        r = 0;
            }
            push(r);
        }
    }
    printf("result = %d\n", pop());
    return 0;
}



//6332^*+5-









