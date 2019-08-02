#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;


int main()
{
    int test, n, i, j, d, s, sum, med;
    int a[10000];
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);
        for(i=0; i<n; i++)
        {
            scanf("%d", &a[i]);
        }
        sort(a, a+n);
        if(n%2==0)
        {
            d=n/2;
            med=a[d];
        }
        else
        {
            d=(n/2)+1;
            med=a[d];
        }
        sum=0;
        for(j=0; j<n; j++)
        {
            s=abs(med-a[j]);
            sum=sum+s;
        }
        printf("%d\n", sum);
    }
    return 0;
}
