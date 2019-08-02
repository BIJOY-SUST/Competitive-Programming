#include<stdio.h>

int main(){
    int n,k,i,j,c=0,a,b,p[50],t[50];
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d %d",&p[i],&t[i]);
    }
    for (i = 0; i < n-1;i++){
        for (j = i + 1; j < n; j++){
            if(p[i] < p[j]){
                a =  p[i];
                p[i] = p[j];
                p[j] = a;
                b = t[i];
                t[i]   = t[j];
                t[j] = b;
            }
            else if(p[i]==p[j]){
                if(t[i]>t[j]){
                    b = t[i];
                    t[i]   = t[j];
                    t[j] = b;
                }
            }
        }
    }
    /*for(i=0;i<n;i++){
        printf("%d %d\n",p[i],t[i]);
    }*/
    for(i=0;i<n;i++){
        if(p[i]==p[k-1] && t[i]==t[k-1]){
            c++;
        }
    }
    printf("%d",c);
    return 0;
}
