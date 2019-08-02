#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n,c=0,d=0;
    cin>>n;
    string s;
    cin>>s;
    if(n<=26){for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(s[i]==s[j]&&i!=j){
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
