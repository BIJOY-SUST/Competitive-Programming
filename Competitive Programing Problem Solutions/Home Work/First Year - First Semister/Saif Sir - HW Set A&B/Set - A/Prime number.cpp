#include <stdio.h>
int main()
{
    int T;
    long int n, i, flag = 0, count = 1;;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=2; i<n; i++){
            if(n%i==0){
                flag=1;
                break;
            }
        }
        if(flag==0 && n>1){
            printf("Case %d : Yes\n", count);
            count++;
        }
        else{
            printf("Case %d : No\n", count);
            count++;
        }
    }
    return 0;
}

