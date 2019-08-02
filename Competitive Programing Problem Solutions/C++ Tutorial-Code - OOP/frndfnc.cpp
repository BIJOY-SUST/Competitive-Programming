#include<bits/stdc++.h>

using namespace std;
class rectangle{
    int h;
    int w;
public:
    void set(int h,int w){
        this->h=h;
        this->w=w;
    }
    int area(){
        return h*w;
    }
};
class con{
    int costrate;
public:
    void setvalue(int costrate){
        this->costrate=costrate;
    }
    int totalcost(rectangle x){
        return costrate*x.area();
    }
};
int main(){
    rectangle r;
    r.set(5,6);
    con d;
    d.setvalue(100);
    cout<<r.area()<<endl;
    cout<<d.totalcost(r)<<endl;

    return 0;
}
