#include<stdio.h>
int main()  {
    int T,i,n1,n2,n3,a,b,c;
    scanf("%d", &T);
    for(i=1; i<=T; i++) {
        scanf("%d %d %d", &n1, &n2, &n3);
        if(n1>n2) {
            if(n1>n3) {
                a=n1;
                if(n2>n3) {
                    b=n2;
                    c=n3;
                }
                else{
                    b=n3;
                    c=n2;
                }
            }
            else{
                b=n1;
                a=n3;
                c=n2;
            }
        }
        else{
            if(n1<n3){
                c=n1;
                if(n2<n3) {
                    b=n2;
                    a=n3;
                }
                else{
                    b=n3;
                    a=n2;
                }
            }
            else{
                a=n2;
                b=n1;
                c=n3;
            }
        }
        printf("Kase %d: %d %d %d\n", i, c,b,a);
        printf("\n");
    }
    return 0;
}
