#include<bits/stdc++.h>
using namespace std;
long long int an[1000001];
int main(){
    long long int N;
    cin>>N;

    for(long long int i=0;i<N;i++){
        cin>>an[i];
    }
    long long int Q;
    cin>>Q;
    long long int value;
    for(int i=0;i<Q;i++){
        cin>>value;
        long long int flag1=0;
        for(long long int j=0;j<N;j++){
            if(value>an[j]){
                flag1=an[j];
            }
            else{
                break;
            }
        }
        if(flag1!=0){
            cout<<flag1<<" ";
        }
        else{
            cout<<"X ";
        }
        long long int flag2=0;
        for(long long int j=N-1;j>=0;j--){
            if(value<an[j]){
                flag2=an[j];
            }
            else{
                break;
            }
        }
        if(flag2!=0){
            cout<<flag2<<endl;;
        }
        else{
            cout<<"X"<<endl;
        }
    }
    return 0;
}
