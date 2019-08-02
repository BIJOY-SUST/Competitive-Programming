#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<cstdio>

using namespace std;
string str1,str2;
int main() {
    long long int T,i,c=0,j,k,N,n1,n2;

    cin>>str1;
    cin>>str2;
    n1=str1.size();
    n2=str2.size();
    for(i=0; i<=(n1-n2); i++){
        if(str2[0] == str1[i]){
            for(j=1; j<n2; j++){
                if(str2[j] != str1[i+j]){
                    break;
                }
            }
            if(j==n2){
                c++;
            }
        }
    }
    cout<<c<<endl;
    return 0;
}
