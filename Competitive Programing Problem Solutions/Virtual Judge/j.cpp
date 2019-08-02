#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int N,Q;
    cin>>N;
    char s[1000][21];
    char ss[1000][21];

    for(int i =0;i<N;i++){
        cin>>s[i];
    }
    cin>>Q;
    for(int i =0;i<Q;i++){
        cin>>ss[i];
    }
    for(int i =0;i<Q;i++){
        int count=0;
        for(int j =0;j<N;j++){
            if((strcmp(ss[i], s[j])==0)){
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}

