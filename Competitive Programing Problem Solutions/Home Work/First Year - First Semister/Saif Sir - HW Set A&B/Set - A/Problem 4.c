#include <stdio.h>
int main()
{
    int ara[10000];
    int n, i, CSum;
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &ara[i]);
    }
    printf("\n\n");
    CSum = ara[0];
    for(i=0; i<n; i++){
        if(i==0){
            printf("%d ", ara[i]);
        }
        else{
            CSum = CSum + ara[i];
            printf("%d ", CSum);
        }
    }
    return 0;
}
