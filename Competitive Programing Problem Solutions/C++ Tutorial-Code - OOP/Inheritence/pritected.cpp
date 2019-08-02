#include<bits/stdc++.h>
using namespace std;

class student{
protected:
    int roll;
    int mark;

};


class result:public student{
public:
    void set(){cin>>roll>>mark;}
    void print(){cout<<roll<<" "<<mark<<endl;}
    void all(){
        set();
        print();
    }
};

int main(){
    result ob;
    ob.mark=5;
    ob.roll=4;
    ///cout<<ob.mark<<" "<<ob.roll<<endl;
    ob.set();
    ob.print();
//    ob.all();
    return 0;
}
