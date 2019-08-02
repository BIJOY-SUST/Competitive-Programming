#include<stdio.h>
#include<math.h>

int main(){
  int participants[55];
  int n,k,max;scanf("%d %d",&n,&k);
  for (int i = 0; i < n; ++i)
  {
    scanf("%d",&participants[i]);
    if(i+1==k)
      max= participants[i];
  }
  int count=0;
  for (int i = 0; i < n; ++i)
  {
    if(participants[i]>=max && participants[i] > 0)
      count++;
  }
  printf("%d",count);

 return 0;
}
