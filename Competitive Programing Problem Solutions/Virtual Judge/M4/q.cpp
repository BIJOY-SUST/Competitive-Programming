#include<bits/stdc++.h>
using namespace std;
int main(){
    string S;
    cin>>S;
    int B=0,b=0,u=0,a=0,s=0,r=0,l=0;
    for(int i=0;i<S.length();i++){
        if(S[i]=='B'){
            B++;
        }
        else if(S[i]=='b'){
            b++;
        }
        else if(S[i]=='l'){
            l++;
        }
        else if(S[i]=='u'){
            u++;
        }
        else if(S[i]=='a'){
            a++;
        }
        else if(S[i]=='r'){
            r++;
        }
        else if(S[i]=='s'){
            s++;
        }
    }
        int k=S.length();
        k=min(k,min(B,b));
        k=min(k,min(l,u/2));
        k=min(k,min(a/2,r));
        k=min(k,s);
        cout<<k<<endl;
    return 0;
}

