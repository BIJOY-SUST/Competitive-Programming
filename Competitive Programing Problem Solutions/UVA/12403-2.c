#include<stdio.h>
#include<string.h>
int main(){
  int T,i,m,s=0;
  char str[1000];
  scanf("%d", &T);
  while(T--){
        scanf("%s", &str);
      if(strcmp( str,"donate" )==0){
        scanf("%d", &m);
        s += m;
      }
      else if( strcmp( str , "report" )==0){
        printf("%d\n", s);
      }
    }
  return 0;
}
