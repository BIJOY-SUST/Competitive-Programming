#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin>>N;
    getchar();
    while(N--){
        char a[100][100];
        for(int i=0;i<3;i++){
            cin>>a[i];
        }
        bool flag = true;
        int c=0,k=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(a[i][j]=='X'){
                    c++;
                }
                if(a[i][j]=='O'){
                    k++;
                }
            }
        }
        if(c>=k){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
    }
    return 0;
}
