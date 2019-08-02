#include<stdio.h>

int main(){
    int i,j,n,m,s,a[10000],c;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&m);
        for(i=0;i<m;i++){
            scanf("%d",&a[i]);
        }
        c = 0;
        for(i=0;i<m;i++){
            for(j=0;j<m-1;j++){
                if(a[j]>a[j+1]){
                    s = a[j];
                    a[j] = a[j+1];
                    a[j+1] = s;
                    c++;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n",c);
    }
    return 0;
}
