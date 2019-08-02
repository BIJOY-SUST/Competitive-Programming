#include<bits/stdc++.h>
#define M_E 2.718281828
#define M_PI 22/7
using namespace std;
int num_digit(int n){
    double x=0;
    for(int i=1;i<=n;i++){
        x+=log10(i);
    }
    int ans=((int)x)+1;
    return ans;
}
///However that solution would not be able to handle cases where n >10^6
///So, can we improve our solution ?
///Yes ! we can.
///We can use Kamenetsky’s formula to find our answer !
//long long num_digit(int n){
//    if(n<0) return 0;
//    if(n<=1) return 1;
//    double x=((n*log10(n/M_E)+log10(2*M_PI*n)/2.0));
//    return floor(x)+1;
//}
int main(){
    int n;
    cin>>n;
    cout<<num_digit(n)<<'\n';
    return 0;
}

