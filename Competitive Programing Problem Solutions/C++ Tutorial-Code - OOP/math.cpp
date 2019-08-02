#include<bits/stdc++.h>
#include<stdio.h>

int call(int a,int b){
    if(a<0||b>4){
        return 0;
    }
    call(a--,b++);
    printf("%d %d",a,b);
    return a;
}
int main(){
    int n;
    n=call(3,2);
    printf("%d",n);

    return 0;
}
