#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    time_t t;
    srand((unsigned)time(&t));
    int i;
    for(i=0;i<5;i++){
        printf("%d\n",rand());
    }

    return 0;
}
