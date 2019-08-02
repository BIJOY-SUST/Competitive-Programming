#include<bits/stdc++.h>
using namespace std;
class f{
    int *p;
public:
    f(){p = new int(0);cout<<"cons...."<<*p<<endl;}
    ~f(){cout<<"dis...."<<*p<<endl;delete p;}
    void set(int x){*p = x;}
    void get(){cout<<*p<<endl;}
    f(f &ob)
    {
        p = new int(1);
        cout<<"Con...."<<*p<<endl;
    }
};
/*f::f(f &ob){
    p = new int(1);
    cout<<"con..."<<*p<<endl;
}*/
int main(){


    f a;
    a.get();
    f b =a;
    a.get();
    b.get();
    b.set(5);
    a.get();
    b.get();

    return 0;
}
