#include<bits/stdc++.h>
using namespace std;
int x,n;
bool print(int i,int s){
    if(n<2) return false;

    if(i>s) return true;

    if(n%i==0) return false;

    print(i+1,s);
}
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        print(2,(int)sqrt(n))? cout<<"Prime"<<endl:cout<<"Not Prime"<<endl;
    }
    return 0;
}

