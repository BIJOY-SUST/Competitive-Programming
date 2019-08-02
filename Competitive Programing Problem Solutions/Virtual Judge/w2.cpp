#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
 int t, a[30], b[30], n, flag;
 char s[1005];
 scanf("%d", &t);
 while(t--) {
  scanf("%s", s);
  for(int i=0; i<30; i++) a[i]=b[i]=0;
  n=strlen(s);
  for(int i=0; i<n/2; i++) {
   a[s[i]-'a']++;
   b[s[n-1-i]-'a']++;
  }
  flag=memcmp(a, b, sizeof(a));
  //cout<<sizeof(a)<<endl;
 // cout<<flag<<endl;
  if(flag==0) printf("YES\n");
  else printf("NO\n");
 }
 return 0;
}

/*#include <stddef.h> /* size_t */
/*
int memcmp(const void* s1, const void* s2,size_t n)
{
    const unsigned char *p1 = s1, *p2 = s2;
    while(n--)
        if( *p1 != *p2 )
            return *p1 - *p2;
        else
            p1++,p2++;
    return 0;
}*/
