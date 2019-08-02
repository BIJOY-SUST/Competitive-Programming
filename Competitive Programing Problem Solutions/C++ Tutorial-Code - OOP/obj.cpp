#include<iostream>

using namespace std;
class rectangle{
    int h;
    int w;
public:
    rectangle(int a,int b){
        h=a;
        w=b;
    }
    int area(){
        return h*w;
    }
};

int main(){
    rectangle obj[5]={rectangle(1,2),rectangle(2,2),rectangle(3,2),rectangle(4,2),rectangle (5,2)};

    for(int i=0;i<5;i++){
        cout<<i<<" "<<obj[i].area()<<endl;
    }
    return 0;
}

