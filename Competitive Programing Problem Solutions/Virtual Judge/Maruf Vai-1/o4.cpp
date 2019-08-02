#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n,c=0,d=0;
    cin>>n;
    string s;
    cin>>s;
    /*for(int i='a';i<='z';i++){
        int cou=count(s.begin(),s.end(),i);
        if(cou>d){
            d=cou;
        }
    }*/
    if(n<=26){for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){                ///cdaadad
            if(s[i]==s[j]&&i!=j){           ///25 peoaicnbisdocqofsqdpgobpn
                c++;
                s[i]=0;

            }
        }
    }
    cout<<c<<endl;
    }
    else{
        cout<<"-1"<<endl;
    }

    return 0;
}
