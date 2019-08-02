#include<bits/stdc++.h>

using namespace std;
class rectangle{
    int height;
    int width;
public:
    void set(int h, int w);
    int area();
    rectangle(int h,int w);
    ~rectangle();
};
int rectangle::area(){
    return height*width;
}
rectangle::rectangle(int h,int w){
    height = h;
    width = w;
    cout<<"Constructor"<<endl;
}
rectangle::~rectangle(){
    cout<<"Destructor"<<endl;
}
int main(){
     rectangle obj(5,6);
     cout<<"Area = "<<obj.area()<<endl;

     return 0;
}
