#include<bits/stdc++.h>
using namespace std;

class student{
private:
    int roll;
    int mark;
public:
    void set(){cin>>roll>>mark;}
    void print(){cout<<roll<<" "<<mark<<endl;}

};

/**class result:public student{
public:
    void all(){
        set();
        print();
    }
};*/
/**class result:private student{
public:
    void all(){
        set();
        print();
    }
};*/
class result:protected student{
public:
    void all(){
        set();
        print();
    }
};


int main(){
    result ob;
    ///ob.mark=5;
    ///ob.roll=4;
    ///cout<<ob.mark<<" "<<ob.roll<<endl;
    //ob.set();
    //ob.print();
    ob.all();
    return 0;
}

