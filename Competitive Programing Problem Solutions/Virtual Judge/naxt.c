#include<stdio.h>
#include<math.h>

int main(){
    int n,m,i,j,k,c=0,a[10000];
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(i+1==k){
            m= a[i];
        }
    }

    for(j=0;j<n;j++){
        if(a[j]>=m&& a[j]>0){
            c++;
        }
    }
    printf("%d\n",c);

    return 0;
}
