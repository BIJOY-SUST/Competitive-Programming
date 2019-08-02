#include<stdio.h>

int main()

{
    int i,n;
    while(scanf("%d",&n)){
        if(n>=1&&n<=4){
            printf("few\n");
        }
        else if(n>=5&&n<=9){
            printf("several\n");
        }
        else if(n>=10&&n<=19){
            printf("pack\n");
        }
        else if(n>=20&&n<=49){
            printf("lots\n");
        }
        else if(n>=50&&n<=99){
            printf("horde\n");
        }
        else if(n>=100&&n<=249){
            printf("throng\n");
        }
        else if(n>=250&&n<=499){
            printf("swarm\n");
        }
        else if(n>=500&&n<=999){
            printf("zounds\n");
        }
        else{
            printf("legion\n");
        }
    }
    return 0;

}
