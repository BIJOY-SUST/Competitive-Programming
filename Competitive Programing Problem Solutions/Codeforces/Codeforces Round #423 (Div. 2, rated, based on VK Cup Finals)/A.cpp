#include<bits/stdc++.h>
using namespace std;
int main(){
int n,a,b,total=0,total1=0,x;
cin>>n>>a>>b;
while(n--){
    cin>>x;
    if(x==1){
            total1++;
        if(a!=0){
            a--;
            total++;
        }
        else if(a==0 && b!=0){
            b--;
            total++;
            a++;
        }
    }
    else if(x==2){
        total1+=2;
        if(b!=0){
            b--;
            total+=2;
        }
    }
}
cout<<total1-total<<endl;
return 0;
}
