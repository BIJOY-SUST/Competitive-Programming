#include<bits/stdc++.h>
using namespace std;
int cal(int x,int y){
    cout<<x<<" "<<y<<endl;
    if(x<0||y>5){
        return 0;
    }
    cal(x-1,y+1);
    cout<<x<<" "<<y<<endl;
    return x;
}
int main(){
    int n = cal(2,3);
    cout<<n<<endl;
}
