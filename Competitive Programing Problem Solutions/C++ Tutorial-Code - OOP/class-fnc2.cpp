#include<bits/stdc++.h>

using namespace std;

class rectangle{
public:
    int h;
    int w;
    int area();
};
int rectangle::area(){

    return h*w;
}
int main(){
    rectangle o;
    o.h = 5;
    o.w = 6;

    cout<<"Area = "<<o.area()<<endl;

    return 0;
}
