#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;
int main()
{
    int i,j,a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    for(i=0;i*a<=c;i++)
    {
        for(j=0;j*b<=c;j++){
        if((a*i+b*j) == c){
            printf("Yes\n");
            return 0;
        }
    }
    }
    printf("No\n");
    return 0;
}
