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
    int h,w;
    cin>>h>>w;
    rectangle kk;
    kk.set(h,w);
    return kk;
}
void print(rectangle abc){
    cout<<abc.area()<<endl;

}
int main(){
     rectangle obj;
    obj = scan();
    print(obj);

     return 0;
}

