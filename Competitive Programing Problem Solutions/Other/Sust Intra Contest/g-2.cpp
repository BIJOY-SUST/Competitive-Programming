#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
int seg(int i){
        if(i==0){
            if(a+b>c&&c+b>a&&a+c>b){
                if(a-b>c&&c-b>a&&a-c>b)
                    return 1;
            }
            else if(a+b==c||c+b==a||a+c==b){
                return 2;
            }
            return 3;
        }
        else if(i==1){
            if(a+b>d&&d+b>a&&a+d>b){
                if(a-b>d&&d-b>a&&a-d>b)
                return 1;
            }
            else if(a+b==d||d+b==a||a+d==b){
                return 2;
            }
            return 3;
        }
        else if(i==2){
            if(a+c>d&&d+c>a&&a+d>c){
                if(a-c>d&&d-c>a&&a-d>c)
                return 1;
            }
            else if(a+c==d||d+c==a||a+d==c){
                return 2;
            }
            return 3;
        }
        else if(i==3){
            if(b+c>d&&d+c>b&&b+d>c){
                if(b-c>d&&d-c>b&&b-d>c)
                return 1;
            }
            else if(b+c==d||d+c==b||b+d==c){
                return 2;
            }
            return 3;
        }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>b>>c>>d;
    int m,p=1;
    for(int i=0;i<4;i++){
        int k=seg(i);
        if(k==1){
                p=2;
                cout<<"TRIANGLE"<<"\n";
                break;
        }
        else if(k==2) m=k;

    }
    if(p==1&&m==2) cout<<"SEGMENT"<<"\n";
    else if(p==1&&m==3) cout<<"IMPOSSIBLE"<<"\n";

    return 0;
}

