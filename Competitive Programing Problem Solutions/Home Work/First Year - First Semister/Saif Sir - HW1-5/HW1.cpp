#include<bits/stdc++.h>
using namespace std;
int main(){
    int i, space, rows, k=0;
    cin>>rows;
    for(i=1; i<=(rows+1)/2; ++i){
        k=0;
        for(space=1; space<=(rows+1)/2-i; ++space){
            printf("  ");
        }
        while(k != 2*i-1){
            printf("* ");
            ++k;
        }
        printf("\n");
    }
    for(i=(rows-1)/2; i>0; i--){
        k=0;
        for(space=1; space<=(rows+1)/2-i; ++space){
            printf("  ");
        }
        while(k != 2*i-1){
            printf("* ");
            ++k;
        }
        printf("\n");
    }
    return 0;
}
