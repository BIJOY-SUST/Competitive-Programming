#include<stdio.h>

void recurse(int count){
    if(count==5){
        return 0;
    }
    printf("Hurrey, I am learning recursion!\n");
    recurse(count+1);
    printf("Hurrey, I am learning recursion!\n");
    return 0;
}
int main(){
    recurse(1);
    return 0;
}
