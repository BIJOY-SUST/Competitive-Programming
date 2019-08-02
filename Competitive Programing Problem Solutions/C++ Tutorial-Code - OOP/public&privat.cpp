#include<bits/stdc++.h>

using namespace std;

class rectangle{
    int h;
    int w;
public:
    void set(int a, int b);
    int area();
};

int rectangle::area(){
    return h*w;
}
void rectangle::set(int a,int b){
    h = a;
    w = b;
}
int main(){
    rectangle o;
    //o.h = 5;
    //o.w = 6;
    o.set(5,6);

    cout<<"Area = "<<o.area()<<endl;

}
