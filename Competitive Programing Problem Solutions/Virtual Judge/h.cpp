#include<bits/stdc++.h>
using namespace std;

int main(){
   signed int A[10][10];
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            cin>>A[i][j];
        }
    }
    int sum,y=-999999;
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(i+2<6&&j+2<6){
                sum = A[i][j]+A[i][j+1]+A[i][j+2]+A[i+1][j+1]+A[i+2][j]+A[i+2][j+1]+A[i+2][j+2];
            }
            if(sum>y){
                y=sum;
            }
        }
    }
    cout<<y<<endl;

    return 0;
}
