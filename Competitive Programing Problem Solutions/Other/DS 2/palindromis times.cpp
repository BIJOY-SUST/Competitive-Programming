#include<bits/stdc++.h>
using namespace std;
int main(){
    int HH,MM;
    scanf("%d:%d",&HH,&MM);
    if(HH==23&&MM>=32){
        printf("00:00\n");
        return 0;
    }
    MM++;
    if(HH==24) HH=0;
    if(MM==60){
        HH++;
        MM=0;
    }
    while(((HH%10)*10+HH/10)!=MM){
        MM++;
        if(HH==24) HH=0;
        if(MM==60){
            HH++;
            MM=0;
        }
    }
    printf("%02d:%02d\n",HH,MM);
    return 0;
}
