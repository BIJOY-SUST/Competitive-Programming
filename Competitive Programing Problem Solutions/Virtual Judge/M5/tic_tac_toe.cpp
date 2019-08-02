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
        int c=0;
        for(int i=0;i<3;i++){
            c=0;
            for(int j=0;j<3;j++){
                if(a[i][j]=='X'){
                    c++;
                }
                if(c==3){
                    cout<<"yes"<<endl;
                    flag = false;
                    break;
                }
            }
            if(flag == false){
                break;
            }
            c=0;
            for(int j=0;j<3;j++){
                if(a[j][i]=='X'){
                    c++;
                }
                if(c==3){
                    cout<<"yes"<<endl;
                    flag = false;
                    break;
                }
            }
            if(flag == false){
                break;
            }
        }
        c=0;
        if(flag==true){
            for(int j=0,k=0;j<3,k<3;j++,k++){
                if(a[j][k]=='X'){
                    c++;
                }
                if(c==3){
                    cout<<"yes"<<endl;
                    flag = false;
                    break;
                }
            }
        }
        c=0;
        if(flag==true){
            for(int j=0,k=2;j<3,k>=0;j++,k--){
                if(a[j][k]=='X'){
                    c++;
                }
                if(c==3){
                    cout<<"yes"<<endl;
                    flag = false;
                    break;
                }
            }
        }
        if(flag==true){
            cout<<"no"<<endl;
        }
        //cout<<endl;
    }
    return 0;
}
