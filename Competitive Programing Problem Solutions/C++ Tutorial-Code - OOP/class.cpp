#include<bits/stdc++.h>

using namespace std;

class rectangle{
public:
    int height;
    int width;
};

int main(){
    rectangle obj;
    obj.height = 5;
    obj.width = 6;

    cout<<"Area = "<<obj.height*obj.width<<endl;

    return 0;
}

