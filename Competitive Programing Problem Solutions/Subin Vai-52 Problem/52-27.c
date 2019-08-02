#include<stdio.h>
#include<math.h>
int main() {
    int T,k,m,n,a,c;
    scanf("%d", &T);
    for(k=1; k<=T; k++) {
        c=0;
        scanf("%d", &n);
        a=n;
        while(n!=0){
            m=n%10;
            c=c+m*m*m;
            n=n/10;
        }
        if(a==c){
            printf("Armstrong\n");
        }
        else{
            printf("Not Armstrong\n");
        }
    }
    return 0;
}
