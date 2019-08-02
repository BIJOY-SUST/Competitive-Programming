#include<bits/stdc++.h>
using namespace std;
int main(){
    int i,N,n,h;
    char c;
    string s;
    cin>>N;
    cin>>s;
    cin>>n;
    if(n>26){
    n =n%26;}
    for(i=0;i<N;i++){
        if(isupper(s[i])){
            if(s[i]+n<=90){
                c = s[i]+n;
                cout<<c;
            }
            else{
                h = ((s[i]+n)-90)%26;
                c = 65 + h-1;
                cout<<c;
            }

        }
        else if(islower(s[i])){
            if(s[i]+n<=122){
                c = s[i]+n;
                cout<<c;
            }
            else{
                h = ((s[i]+n)-122)%26;
                c = 97 + h-1;
                cout<<c;
            }

        }
        else{
            cout<<s[i];
        }
    }
    cout<<endl;
    return 0;
}

