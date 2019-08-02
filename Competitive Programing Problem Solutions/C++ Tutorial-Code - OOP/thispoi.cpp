#include<bits/stdc++.h>

using namespace std;
class rectangle{
    int h;
    int w;
public:
    void set(int a, int b){
    this->h=a;
    this->w=b;
    }
    int area(){
    return h*w;
    }
};

int main(){
     rectangle obj;
    obj.set(2,3);
     cout<<"Area = "<<obj.area()<<endl;

     return 0;
}
