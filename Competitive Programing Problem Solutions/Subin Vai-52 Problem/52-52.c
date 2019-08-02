 #include<stdio.h>

int main() {
    int T,i,c,j,k,N,n1,n2;
    char str1[100], str2[100];

    scanf("%d", &T);
    while(T--){
    c=0;
    scanf(" %[^\n]",str1);
    scanf(" %[^\n]",str2);
    n1=strlen(str1);
    n2=strlen(str2);
    for(i=0; i<=(n1-n2); i++){
        if(str2[0] == str1[i]){
            for(j=1; j<n2; j++){
                if(str2[j] != str1[i+j]){
                    break;
                }
            }
            if(j==n2){
                c++;
            }
        }
    }
    printf("%d\n", c);
    }
    return 0;
}

