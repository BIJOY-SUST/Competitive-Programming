#include<bits/stdc++.h>
using namespace std;
int main(){
    int c=0,N,A[101][27];
    memset(A,-1,sizeof A);
    string s;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>s;
        for(int j=0;j<s.length();j++){
            A[i][s[j]-'a'] = 0;///Thanks 2D Graph..............
        }
    }
    for(int i=0;i<26;i++){
        bool m = false;
        for(int j=0;j<N;j++){
            if(A[j][i]==-1){
                m = true;
            }
            if(m==false&&j==N-1){
                c++;
            }
        }
    }
    cout<<c<<endl;
    return 0;
}
