#include <string.h>

unsigned long int fact(int n, int k){
   unsigned long int p=1;
   int i;
   i=n;
   while(i>0){
      p*=i;
      i=i-k;
      }
   return p;
   }

void main(){
   int n,k;
   cin>>n;
   char a[25];
   cin.getline(a,24,'\n');
   k=strlen(a)-1;
   cout<<fact(n,k);
   }
