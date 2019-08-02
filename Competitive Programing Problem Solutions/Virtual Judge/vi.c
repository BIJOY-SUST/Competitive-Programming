#include<stdio.h>
int main(){
    int i,n,k,j,ara[100],d,m,sum;
    scanf("%d %d",&k,&n);
        sum=0;
        d=0;
        m=k*n;
        for(i=0;i<n;i++){
            scanf("%d",&ara[i]);
            sum+=ara[i];
            if(sum>m){
                d+=sum-m;
            }
        }

    printf("%d\n",d);
    return 0;
}

