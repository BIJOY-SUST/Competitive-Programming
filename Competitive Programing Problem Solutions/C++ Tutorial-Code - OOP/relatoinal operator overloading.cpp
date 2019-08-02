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

    number operator + (number ob);
    bool operator > (number ob);
    bool operator < (number ob);
    bool operator == (number ob);
};
number number::operator + (number ob){
    number tmp;
    tmp.x = x+ob.x;
    tmp.y = y+ob.y;

    return tmp;
}

bool number::operator > (number ob){
    return (x+y) > (ob.x+ob.y);
}
bool number::operator <(number ob){
    return (x+y) < (ob.x+ob.y);
}
bool number::operator == (number ob){
    return (x+y) == (ob.x+ob.y);
}

int main(){
    number n1(4,6),n2(4,4),n3;
    n3=n1+n2;
    n3.print();

    if(n1>n2) cout<<"n1"<<endl;
    else if(n1==n2) cout<<"n1=n2"<<endl;
    else cout<<"n2"<<endl;

    return 0;
}
