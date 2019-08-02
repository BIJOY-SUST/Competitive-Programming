#include<bits/stdc++.h>
using namespace std;
int n;
void print(int i){
    if(i<n){
        if(i==0){
            cout<<"1";
        }
        else{
            cout<<" + x";
            printf("^%d",i);
        }
        print(++i);
    }
}
int main(){
    cin>>n;
    print(0);

    return 0;
}
