#include<bits/stdc++.h>
using namespace std;
class exampleConst{
public:
    int a;
    int change(int x)const{
        x = a+x;
        return x;
    }
};
int main(){
    /*const int d = 123;
    //=3;
    int a[d];*/
    int i=0;
    const int& r = i;
     r=3;
    return 0;
}
