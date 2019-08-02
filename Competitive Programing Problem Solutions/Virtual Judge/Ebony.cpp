#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;
int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(a>b){
        if((a*1+b*2) == c){
            printf("Yes\n");
        }
    }
    else{
        if((a*1+b*0) == c){
            printf("Yes\n");
        }
        else{
        printf("No\n");
        }
    }
    return 0;
}
