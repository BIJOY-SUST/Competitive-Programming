#include<bits/stdc++.h>
using namespace std;
int Dec_to_Bi(int m){
    int  bin = 0, i = 1, reminder;
    while(m != 0) {
        reminder = m%2;
        m = m/2;
        bin = bin + (reminder*i);
        i = i*10;
    }
    return bin;
}
int main(){
    int n;
    cin>>n;
    cout<<Dec_to_Bi(n)<<endl;
    return 0;
}

