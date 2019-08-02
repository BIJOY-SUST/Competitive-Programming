#include <stdio.h>
int main(){
    long long int i,temp,N,P, c=100007;
    while(scanf("%lld %lld", &N, &P) && N!=0 && P!=0){
        temp = 1;
        for(i=1; i<=P; i++){
            temp = temp*N;
            if(temp == c){
                temp = 0;
            }
            else if(temp>c){
                temp=temp%c;
            }
        }
        printf("%lld\n",temp%c);
    }
    return 0;
}
