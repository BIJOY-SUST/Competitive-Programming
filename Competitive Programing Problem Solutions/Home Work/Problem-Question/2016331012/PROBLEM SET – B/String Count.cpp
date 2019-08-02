#include<stdio.h>
#include<string.h>

int main()
{
    int i,j,len,vc=0,cc=0,nc=0;
    double vcc,ccc,ncc;
    char p = '%';
    char S[1000];
    gets(S);
    len = strlen(S);
    for(j=0; j<len;j++) {
        if(S[j]=='a'||S[j]=='e'||S[j]=='i'||S[j]=='o'||S[j]=='u'||S[j]=='A'||S[j]=='E'||S[j]=='I'||S[j]=='O'||S[j]=='U'){
            vc++;
        }
        else if(S[j] >= '0' && S[j] <= '9'){
            nc++;
        }

    }
    //printf("%d\n", vc);
    cc = len - vc - nc;
    vcc = (double)vc*100/(double)len;
    ccc = (double)cc*100/(double)len;
    ncc = (double)nc*100/(double)len;
    printf("Vowels = %.2lf%c\nConsonants = %.2lf%c\nDigits = %.2lf%c\n", vcc,p, ccc,p, ncc,p);
    return 0;
}
