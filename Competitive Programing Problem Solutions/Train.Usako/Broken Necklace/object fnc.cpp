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

int main(){
     rectangle obj;
     rectangle *p;
     obj.set(3,4);
     cout<<"Area = "<<obj.area()<<endl;
     p=&obj;
     p->set(2,7);
     cout<<"Area = "<<obj.area()<<endl;

     return 0;
}
