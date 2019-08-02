#include<stdio.h>

int main(){
  int T,i,j,N,min;
  while(scanf("%d", &T)==1){
  for(i=1;i<=T;i++){
    scanf("%d",&N);
    int ara[N];
    for(j=0; j<N; j++){
        scanf("%d", &ara[j]);
    }
    min = ara[0];
    for (j = 1; j <N; j++){
        if (ara[j] > min){
            min = ara[j];
        }
    }
    printf("Case %d: %d\n",i,min);
    }
  }
    return 0;
}
