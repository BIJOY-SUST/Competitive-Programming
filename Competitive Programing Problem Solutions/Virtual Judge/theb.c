#include<stdio.h>
int main(){
    int i,j,n,d,r,ara1[100],ara2[100],sum,pay,swap;
    while(scanf("%d %d %d",&n,&d,&r)==3){
            //while (EOF != scanf("%d %d %d", &n, &d, &r) && (n || d || r)) {

        if(n==0 && d==0 && r==0){
            break;
        }
        pay = 0;
        for(i=0;i<n;i++){
            scanf("%d",&ara1[i]);
        }
        for (i = 0 ; i < ( n - 1 ); i++)
        {
            for (j = 0 ; j < n - i - 1; j++)
            {
                if (ara1[j] > ara1[j+1])
                {
                    swap       = ara1[j];
                    swap       = ara1[j];
                    ara1[j]   = ara1[j+1];
                    ara1[j+1] = swap;
                }
            }
        }
        for(i=0;i<n;i++){
            scanf("%d",&ara2[i]);
        }
        for (i = 0 ; i < ( n - 1 ); i++)
        {
            for (j = 0 ; j < n - i - 1; j++)
            {
                if (ara2[j] > ara2[j+1])
                {
                    swap       = ara2[j];
                    swap       = ara2[j];
                    ara2[j]   = ara2[j+1];
                    ara1[j+1] = swap;
                }
            }
        }
        for(i=0;i<n;i++){
            sum = ara1[i]+ara2[n-1-i];
            if(sum>d){
                pay += (sum-d)*r;

            }
        }
        printf("%d\n",pay);
    }
    return 0;
}
