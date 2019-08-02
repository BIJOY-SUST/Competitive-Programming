#include <stdio.h>
int main()
{
    int T;
    long long int n, i, flag;
    scanf("%d",&T);
    while(T--){
        scanf("%lld",&n);
        flag = 0;
        for(i=2; i<n; i++){ //Best equation : for(i=2; i<=n/2; i++)
            if(n%i==0){          // condition for nonprime number
                flag=1;
                break;
            }
        }
        if (flag==0 && n>1){
            printf("%lld is a prime number.\n",n);
        }
        else{
            printf("%lld is not a prime number.\n",n);
        }
    }
    return 0;
}

