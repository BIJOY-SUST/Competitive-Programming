#include <stdio.h>
int main(){
   int N, i, j, T[3000], F[3000];

   while(scanf("%d",&N) == 1){
      for(i = 0; i < N; i++){
         scanf("%d",&T[i]);
         F[i] = 0;
      }
      j = N-1;
      for(i = 0; i < j; i++)
         F[abs(T[i]-T[i+1])] = 1;
      j = 1;
      for(i = 1; i < N; i++){
         if(!F[i]){
            j = 0;
            break;
         }
      }
      if(j==1)
         printf("Jolly\n");
      else
         printf("Not jolly\n");
   }
   return 0;
}
