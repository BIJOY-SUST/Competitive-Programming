#include<stdio.h>

struct Record{
    char name[10];
    char phone[15];
    char email[15];
};
int main(){
   struct Record a;
   scanf("%s",&a.name);
   scanf("%s",&a.phone);
   scanf("%s",&a.email);

   printf("Name: %s, Phone: %s, Email: %s\n",a.name,a.phone,a.email);
   return 0;
}
