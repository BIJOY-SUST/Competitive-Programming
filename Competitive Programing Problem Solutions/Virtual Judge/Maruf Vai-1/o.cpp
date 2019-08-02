#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n,c=0;
    cin>>n;
    char s[100001];
    cin>>s;
    //sort(s,s+n);
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){                ///cdaadad
            if(s[i]==s[j]&&i!=j){           ///25 peoaicnbisdocqofsqdpgobpn
                c++;
                s[i]=0;

            }
        }
    }
    cout<<c<<endl;
    return 0;
}

