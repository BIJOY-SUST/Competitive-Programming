#include<bits/stdc++.h>
using namespace std;
int num_digit(int n){
    int ans=((int)log10(n))+1;
    return ans;
}
int main(){
    int n;
    cin>>n;
    cout<<num_digit(n)<<'\n';
    return 0;
}
