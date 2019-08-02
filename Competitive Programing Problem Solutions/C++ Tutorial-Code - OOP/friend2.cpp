#include<bits/stdc++.h>
using namespace std;

class rectangle;

class cost{
    int costrate;
public:
    void setvalue(int s){
        costrate=s;
    }
    int totalcost(rectangle x);
};

class rectangle{
    int height;
    int width;
public:
    void set(int h,int w){
        height=h;
        width=w;
    }
    int area(){
        return height*width;
    }
    friend int cost::totalcost(rectangle x);
};
int cost::totalcost(rectangle x){
        return costrate*x.height*x.width;
}

int main(){
    rectangle r;
    r.set(5,6);
    cost d;
    d.setvalue(100);
    cout<<r.area()<<endl;
    cout<<d.totalcost(r)<<endl;

    return 0;
}

