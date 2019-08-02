#include<stdio.h>

int main(){
  int T,i,H,M,h,m;

  scanf("%d", &T);
  while(T--){
        scanf("%d",&H);
        scanf("%c",&h);
        scanf("%d",&M);
        if(H==12&&M==0){
            printf("%.2d:%.2d\n",H,M);
        }
        else if(H==12&&M>0){
            printf("%.2d:%.2d\n",H-1,60-M);
        }
        else if(H==11&&M>0){
            printf("%.2d:%.2d\n",H+1,60-M);
        }
        else if(H>0&&M==0){
            printf("%.2d:%.2d\n",12-H,M);
        }
        else if(H>0&&M>0){
            printf("%.2d:%.2d\n",12-H-1,60-M);
        }
    }
  return 0;
}

