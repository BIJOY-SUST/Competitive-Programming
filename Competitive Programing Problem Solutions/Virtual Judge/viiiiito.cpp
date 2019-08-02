#include<cstdio>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>

using namespace std;
int main(){
    int T,s;
    cin>>T;
    while(T--){
        cin>>s;
        int ara[s];
        for(int i=0;i<s;i++){
            cin>>ara[i];
        }
        sort(ara,ara+s);
        int m=0;
        if(s%2==0){
            int mid = s/2;
            for(int i=0;i<s;i++){
                m += abs(ara[mid-1]-ara[i]);
            }
            cout<<m<<endl;
        }
        else{
            int mid = (s+1)/2;
            for(int i=0;i<s;i++){
                m += abs(ara[mid-1]-ara[i]);
            }
            cout<<m<<endl;
        }
    }
    return 0;
}
