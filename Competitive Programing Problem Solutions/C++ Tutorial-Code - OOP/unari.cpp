#include<bits/stdc++.h>
using namespace std;
class number{
    int x,y;
public:
    number(){x=0;y=0;}
    number(int a,int b){x=a;y=b;}
    void get(int &a,int &b){a=x;b=y;}
    void set(int a,int b){x=a,y=b;}
    void print(){cout<<x<<" "<<y<<endl;}

    number operator ++ ();
    number operator ++ (int a);



};
number number::operator++(){
    number t;
    x++;y++;
    t.x=x;
    t.y=y;
    return t;
}
number number::operator++(int a){
    number t;
    t.x=x;
    t.y=y;
    x++;y++;
    return t;
}

int main(){
    number n1(4,0),n2(4,4),n3;
    cout<<"n1 ->before ";n1.print();
    n3=n1++;
    cout<<"n1 ->after ";n1.print();
    n3.print();


    return 0;
}

