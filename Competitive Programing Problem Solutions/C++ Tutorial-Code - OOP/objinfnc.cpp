#include<bits/stdc++.h>

using namespace std;
class rectangle{
    int h;
    int w;
public:
    void set(int h, int w){
    this->h=h;
    this->w=w;
    }
    int area(){
    return h*w;
    }
};
rectangle scan(){
    int hi,wi;
    cin>>hi>>wi;
    rectangle ob;
    ob.set(hi,wi);
    return ob;
}
void print(rectangle a){
    cout<<a.area()<<endl;
}
int main(){
     rectangle obj;
     obj = scan();
     print(obj);
     return 0;
}
