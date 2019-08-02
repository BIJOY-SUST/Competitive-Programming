#include<stdio.h>

int main(){
  int T,i,j,N;
  int max,m;
  while(scanf("%d", &T)==1){
  for(i=1;i<=T;i++){
    max = 0;
    scanf("%d",&N);
    for(j=0; j<N; j++){
        scanf("%d",&m);
        if(m>max){
            max = m;
        }
    }
    printf("Case %d: %d\n",i,max);
    }
  }
  return 0;
}
