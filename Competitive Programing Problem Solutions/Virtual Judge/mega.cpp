#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int i,n,k,j,ara[100],d,m,sum;
    scanf("%d %d",&k,&n);
        sum=0;
        m=k*n;
        for(i=0;i<n;i++){
            scanf("%d",&ara[i]);
            sum+=ara[i];
        }
        if(sum>m){
            d=sum-m;
            printf("%d\n",d);
        }
        else{
            printf("0\n");
        }
    return 0;
}
