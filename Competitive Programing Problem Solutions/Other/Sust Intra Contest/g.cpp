#include<bits/stdc++.h>
using namespace std;
int seg(int i){
    if(i==0){
            if(a+b>c&&c+b>a&&a+c>b){
                return 1;
            }
            else if(a+b==c||c+b==a||a+c==b){
                return 2;
            }
            else{
                cout<<"IMPOSSIBLE"<<"\n";
            }
        }
        else if(i==1){
            if(a+b>d&&d+b>a&&a+d>b){
                cout<<"TRIANGLE"<<"\n";
            }
            else if(a+b==d||d+b==a||a+d==b){
                cout<<"SEGMENT"<<"\n";
            }
            else{
                cout<<"IMPOSSIBLE"<<"\n";
            }
        }
        else if(i==2){
            if(a+c>d&&d+c>a&&a+d>c){
                cout<<"TRIANGLE"<<"\n";
            }
            else if(a+c==d||d+c==a||a+d==c){
                cout<<"SEGMENT"<<"\n";
            }
            else{
                cout<<"IMPOSSIBLE"<<"\n";
            }
        }
        else if(i==3){
            if(b+c>d&&d+c>b&&b+d>c){
                cout<<"TRIANGLE"<<"\n";
            }
            else if(b+c==d||d+c==b||b+d==c){
                cout<<"SEGMENT"<<"\n";
            }
            else{
                cout<<"IMPOSSIBLE"<<"\n";
            }
        }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    for(int i=0;i<4;i++){
        if(i==0){
            if(a+b>c&&c+b>a&&a+c>b){
                cout<<"TRIANGLE"<<"\n";
            }
            else if(a+b==c||c+b==a||a+c==b){
                cout<<"SEGMENT"<<"\n";
            }
            else{
                cout<<"IMPOSSIBLE"<<"\n";
            }
        }
        else if(i==1){
            if(a+b>d&&d+b>a&&a+d>b){
                cout<<"TRIANGLE"<<"\n";
            }
            else if(a+b==d||d+b==a||a+d==b){
                cout<<"SEGMENT"<<"\n";
            }
            else{
                cout<<"IMPOSSIBLE"<<"\n";
            }
        }
        else if(i==2){
            if(a+c>d&&d+c>a&&a+d>c){
                cout<<"TRIANGLE"<<"\n";
            }
            else if(a+c==d||d+c==a||a+d==c){
                cout<<"SEGMENT"<<"\n";
            }
            else{
                cout<<"IMPOSSIBLE"<<"\n";
            }
        }
        else if(i==3){
            if(b+c>d&&d+c>b&&b+d>c){
                cout<<"TRIANGLE"<<"\n";
            }
            else if(b+c==d||d+c==b||b+d==c){
                cout<<"SEGMENT"<<"\n";
            }
            else{
                cout<<"IMPOSSIBLE"<<"\n";
            }
        }
    }
    return 0;
}

