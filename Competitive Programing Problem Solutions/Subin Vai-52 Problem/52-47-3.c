#include<stdio.h>
#include<string.h>
int main()
{
    int str1[100], str2[100], str3[100];
    int i,T,T2,k,m,j,n1,n2,n3;
    scanf("%d", &T);
    printf("\n");
    while(T--) {

        scanf("%d",&n1);
        printf("\n");
        for(k=0; k<n1; k++) {
            scanf("%d", &str1[k]);
        }
        printf("\n");
        scanf("%d",&n2);
        printf("\n");
        for(k=0; k<n2; k++) {
            scanf("%d", &str2[k]);
        }
        printf("\n");
        for(i=0,j=0; i<n1;i++, j++)
        {
            str3[j]=str1[i];
        }
        for(i=0; i<n2;i++, j++)
        {
            str3[j]=str2[i];
        }
        n3=n1+n2;
        for(i=0; i<n3; i++) {
            printf("%d ", str3[i]);
        }
        printf("\n");


        for(i=0; i<n3-1; i++) {
            for(j=0; j<n3-i-1; j++){
                if(str3[j]>str3[j+1]){
                    m = str3[j];
                    str3[j] = str3[j+1];
                    str3[j+1] = m;
                }
            }
        }
        for(i=0; i<n3; i++) {
            printf("%d ", str3[i]);
        }
        printf("\n");
    }
    return 0;
}

