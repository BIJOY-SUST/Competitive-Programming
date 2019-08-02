#include<stdio.h>

int main() {
 char prnt = '*';
 int i, j, k, s, nos = -1;
 for (i = 5; i >= 1; i--) {
  for (j = 1; j <= i; j++) {  printf("%2c", prnt); } for (s = nos; s >= 1; s--) {
   printf("  ");
  }
  for (k = 1; k <= i; k++) {
   if (i == 5 && k == 5) {
    continue;
   }
   printf("%2c", prnt);
  }
  nos = nos + 2;
  printf("\n");
 }
 nos = 5;
 for (i = 2; i <= 5; i++) {
  for (j = 1; j <= i; j++)
 {
printf("%2c", prnt);
}
 for (s = nos; s >= 1; s--)
 {
   printf("  ");
  }
  for (k = 1; k <= i; k++) {
   if (i == 5 && k == 5) {
    break;
   }
   printf("%2c", prnt);
  }
  nos = nos - 2;
  printf("\n");
 }
 return 0;
}
