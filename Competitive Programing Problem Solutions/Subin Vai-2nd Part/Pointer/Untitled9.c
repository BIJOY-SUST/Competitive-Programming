#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    time_t currentTime;
    time(&currentTime);

    printf("%s\n",ctime(&currentTime));

    return 0;
}
