#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,T;
    cin>>T;
    for(int A=1;A<=T;A++){
    cin>>t;
    int a[t][t];
    int C=0;
    set<int>s;
    for(int i=0;i<t;i++){
        for(int j=0;j<t;j++)cin>>a[i][j];
    }
    if(t>4){
        if(t==10){
        for(int i=0;i<t;i++){
            for(int j=0;j<t;j++){
                s.insert(a[i][j]);
            }
            if(s.size()==10)C++;
       s.clear();
        }
        for(int i=0;i<t;i++){
            for(int j=0;j<t;j++){
                s.insert(a[j][i]);
            }
       if(s.size()==10)C++;
       s.clear();
        }
        }
    for(int i=0,j=1;i<t-1;i++,j++){
        int x=0;
        while(t-x>=0){
            for(int k=x;k<x+5 && x+5<=t;k++)s.insert(a[i][k]);
            for(int k=x;k<x+5 && x+5<=t;k++)s.insert(a[j][k]);
            if(s.size()==10)C++;
                    x++;
                    s.clear();

        }
    }
    for(int i=0,j=1;i<t-1;i++,j++){
        int x=0;
        while(t-x>=0){
            for(int k=x;k<x+5 && x+5<=t;k++)s.insert(a[k][i]);
            for(int k=x;k<x+5 && x+5<=t;k++)s.insert(a[k][j]);
            if(s.size()==10)C++;
            x++;
            s.clear();
        }
        }
        cout<<"Case "<<A<<": "<<C<<endl;
    }
    else cout<<"Case "<<A<<": 0"<<endl;
    }
    return 0;
}
