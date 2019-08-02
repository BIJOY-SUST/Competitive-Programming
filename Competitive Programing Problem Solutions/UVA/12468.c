#include<stdio.h>
int main(){

    int i,j,k,P,F,count1,count2;
    while(scanf("%d %d", &P, &F)){
        count1 = 0;
        count2 = 0;
        if(P == -1 && F == -1){
            break;
        }
        if(P<F){
            for(i=P; i<=F; i++){
                count1++;
            }
            for(j=P; j>=0; j--){
                count2++;
            }
            for(k=99; k>=F; k--){
                count2++;
            }
            if(count1 < count2){
                printf("%d\n",count1-1);
            }
            else{
                printf("%d\n",count2-1);
            }

        }
        else if(P>F){
            for(i=P; i>=F; i--){
                count1++;
            }
            for(j=P; j<=99; j++){
                count2++;
            }
            for(k=0; k<=F; k++){
                count2++;
            }
            if(count1 < count2){
                printf("%d\n",count1-1);
            }
            else{
                printf("%d\n",count2-1);
            }
        }
    }
    return 0;
}



















