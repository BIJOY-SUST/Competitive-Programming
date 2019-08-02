#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    char s[11][100] = {"zero","one","two","three","four","five","six","seven","eight","nine","ten"};
    char ss[10][100] = {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    char sss[10][100] = {"twenty", "thirty","forty","fifty", "sixty","seventy","eighty","ninety"};
    if(n<=10){
        cout<<s[n]<<endl;
    }
    else if(n>=11&&n<20){
        cout<<ss[n-11]<<endl;
    }
    else if(n>=20&&n<=99){
        int k = n/10;
        int h = n%10;
        if(h!=0){
            cout<<sss[k-2]<<"-"<<s[h]<<endl;
        }
        else{
            cout<<sss[k-2]<<endl;
        }
    }
    return 0;
}

