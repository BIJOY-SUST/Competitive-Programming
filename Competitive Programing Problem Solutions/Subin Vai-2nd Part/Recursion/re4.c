#include<stdio.h>

void recurse(int count){
    if(count==5){
        return 0;
    }
    //printf("Count = %d\n",count);
    recurse(count+1);
    printf("Count = %d\n",count);
    return 0;
}
int main(){
    recurse(1);
    return 0;
}
