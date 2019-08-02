#include<bits/stdc++.h>
using namespace std;

class student{
public:
    int roll;
    int mark;
};

/**class result:public student{
public:
    void set(){cin>>roll>>mark;}
    void print(){cout<<roll<<" "<<mark<<endl;}

};*/
/**class result:private student{
public:
    void set(){cin>>roll>>mark;}
    void print(){cout<<roll<<" "<<mark<<endl;}

};*/
class result:protected student{
public:
    void set(){cin>>roll>>mark;}
    void print(){cout<<roll<<" "<<mark<<endl;}

};

int main(){
    result ob;
    ///ob.mark=5;
    ///ob.roll=4;
    ///cout<<ob.mark<<" "<<ob.roll<<endl;
    ob.set();
    ob.print();
    return 0;
}
