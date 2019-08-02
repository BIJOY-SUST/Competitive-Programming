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
        for(k=1; k<=i; k++){
            printf("%d ",k);
        }
        for(k=i-1; k>0; k--){
            printf("%d ",k);
        }
        printf("\n");
    }
    for(i=(rows-1)/2; i>0; i--){
        k=0;
        for(space=1; space<=(rows+1)/2-i; ++space){
            printf("  ");
        }
        for(k=1; k<=i; k++){
            printf("%d ",k);
        }
        for(k=i-1; k>0; k--){
            printf("%d ",k);
        }
        printf("\n");
    }
    return 0;
}

