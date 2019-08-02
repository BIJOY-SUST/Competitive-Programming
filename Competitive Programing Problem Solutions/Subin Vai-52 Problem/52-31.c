#include<stdio.h>
#include<math.h>

int main(){
    long int T,i,s,j,N,sqrti;
    scanf("%ld", &T);
    while(T--){
        scanf("%ld", &N);
        for(i=1; i<=N; i++){
            s=0;
            for(j=1; j<i; j++){
                if(i%j == 0){
                    s+=j;
                }
            }
            if(s==i){
                printf("%ld\n",i);
            }
        }
    }
    return 0;
}
/*#include<stdio.h>
    int main(){
      int n,i=1,sum=0;

      printf("Enter a number: ");
      scanf("%d",&n);

      while(i<n){
          if(n%i==0)
               sum=sum+i;
              i++;
      }
      if(sum==n)
          printf("%d is a perfect number",i);
      else
          printf("%d is not a perfect number",i);

      return 0;
    }*/
