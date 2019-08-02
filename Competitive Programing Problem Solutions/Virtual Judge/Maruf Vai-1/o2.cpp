#include<bits/stdc++.h>
using namespace std;
int main(){
        long long int N,c=0,d=0;
        cin>>N;
        string a;
        int b[26];
        cin>>a;
        for(int i='a';i<='z';i++){
            b[i]=1;
            int cou=count(a.begin(),a.end(),i);
            if(cou>d){
                d=cou;
            }
        }

        for(int i=0;i<N;i++){
            if(b[a[i]]){
                c++;
                b[a[i]]=0;
            }
        }
        if(d<=26)cout<<N-c<<endl;
        else cout<<"-1"<<endl;
    return 0;
}
