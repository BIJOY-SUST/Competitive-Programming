#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int i,n,T,j,ara[10000],d,mid,sum;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&ara[i]);
    }
    sort(ara,ara+n+1);
    if(n%2==0){
        d=n/2;
        mid=ara[d];
    }
    else{
        d=(n/2)+1;
        mid=ara[d];
    }
    sum=0;
    for(j=1;j<=n;j++){
        sum+=abs(mid-ara[j]);
    }
    printf("%d\n",sum);
    }
    return 0;
}
