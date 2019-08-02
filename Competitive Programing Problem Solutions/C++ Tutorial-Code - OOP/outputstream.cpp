#include<bits/stdc++.h>
using namespace std;
class number{
    int x,y;
public:
    number(){x=0;y=0;}
    number(int a,int b){x=a;y=b;}
    //void get(int &a,int &b){a=x;b=y;}
    //void set(int a,int b){x=a,y=b;}
    //void print(){cout<<x<<" "<<y<<endl;}

    friend void operator << (ostream &os,number ob){
        os<<ob.x<<" "<<ob.y<<endl;
    }
};

int main(){
    number n1(1,4),n2(2,3),n3;
    cout<<n1;
    return 0;
}
