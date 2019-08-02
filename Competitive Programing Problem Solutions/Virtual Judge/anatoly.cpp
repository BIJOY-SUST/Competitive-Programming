#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdlib>

using namespace std;
string s;
int main(){
    int n,x1=0,x2=0;
    cin>>n;
    cin>>s;
    for(int i=0;i<n;i++){
        if(i%2){
            if(s[i]=='b'){
                x1++;
            }
        }
        else{
            if(s[i]=='r'){
                x2++;
            }
        }
    }
    int mov1 = max(x1,x2);
    x1=0;
    x2=0;
    for(int i=0;i<n;i++){
        if(i%2){
            if(s[i]=='r'){
                x1++;
            }
        }
        else{
            if(s[i]=='b'){
                x2++;
            }
        }
    }
    int mov2 = max(x1,x2);

    int mov = min(mov1,mov2);
    cout<<mov<<endl;
    return 0;
}
