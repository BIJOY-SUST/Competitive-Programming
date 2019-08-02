#include<bits/stdc++.h>
using namespace std;
class abc{
    int a;
public:
    abc(int x){a=x;}
    abc(){a=0;}
    int ret(){return a;}
};
int main(){
    abc ob(5);
    abc ob1;
    cout<<ob.ret()<<endl;
    cout<<ob1.ret()<<endl;
}
