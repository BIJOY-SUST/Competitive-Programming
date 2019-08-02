#include<cstdio>
#include<iostream>

using namespace std;

int main(){
    int n,x1,x2;
    int x=0,d=0;
    scanf("%d", &n);
    while (n--){
        scanf("%d%d",&x1,&x2);
        x -= x1;
        x += x2;
        if (x > d){
            d = x;
        }
        else{
            d = d;
        }
    }
    printf("%d\n",d);

    return 0;
}
