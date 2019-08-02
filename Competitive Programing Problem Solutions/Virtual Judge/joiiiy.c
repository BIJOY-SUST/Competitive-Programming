#include<stdio.h>
#include<stdlib.h>
int main(){
    int i,j,n,div,flag;
    int s[3000];
    while(scanf("%d",&n)==1){
        flag = 0;
        for(j=0;j<n;j++){
            scanf("%d",&s[j]);
        }
        for(i=0;i<n-1;i++){
            div = abs(s[i] - s[i+1]);
            if(div>=1 && div<n){
                flag++;
            }
        }
        if(flag == (n-1)){
            printf("Jolly\n");
        }
        else{
            printf("Not jolly\n");
        }
    }
}
