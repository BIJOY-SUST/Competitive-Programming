#include<bits/stdc++.h>
using namespace std;
class number{
    int x,y;
public:
    number(){x=0;y=0;}
    number(int a,int b){x=a;y=b;}
    number(int a){x=a;y=0;}
    //void get(int &a,int &b){a=x;b=y;}
    //void set(int a,int b){x=a,y=b;}
    void print(){cout<<x<<" "<<y<<endl;}

    operator int(){
        return x+y;
    }
    //friend void operator << (ostream &os,number ob){
        //os<<ob.x<<" "<<ob.y<<endl;
   // }
};
class number1{
    int x;
public:
    number1(){x=0;}
    number1(int a){x=a;}
    //void get(int &a,int &b){a=x;b=y;}
    //void set(int a,int b){x=a,y=b;}
    void print(){cout<<x<<endl;}

    operator number(){
        number t(x);
        return t;
    }
    //friend void operator << (ostream &os,number ob){
        //os<<ob.x<<" "<<ob.y<<endl;
   // }
};
int main(){
    number n1(1,4),n2(2,3),n3;
    ///build=class
    //int a=5;
    //n1=a;
    //n1.print();
    ///class=build
    //int a;
    //a=n1;
   // cout<<a<<endl;
   ///class=class
   number1 x1;
   x1=4;
   n1=x1;
   n1.print();


    return 0;
}
