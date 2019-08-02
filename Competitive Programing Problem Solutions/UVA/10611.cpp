#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin>>N;
    int an[1000];
    for(int i=0;i<N;i++){
        cin>>an[i];
    }
    int Q;
    cin>>Q;
    int aq[10000];
    for(int i=0;i<Q;i++){
        cin>>aq[i];
    }
    int j,k;
    for(int i=0;i<Q;i++){
        bool ff=true;
        bool fb=true;
        int f,b;
        for(j=0;j<N;j++){
            if(aq[i]<an[j]&&ff==true){
                f=j;
                ff=false;
            }
        }
        for(k=N-1;k>=0;k--){
            if(aq[i]>an[k]&&fb==true){
                b=k;
                fb=false;
            }
        }
        if(ff==false&&fb==false){
            cout<<an[b]<<" "<<an[f]<<endl;
        }
        else if(ff==false&&fb==true){
            cout<<"X"<<" "<<an[f]<<endl;
        }
        else if(ff==true&&fb==false){
            cout<<an[b]<<" "<<"X"<<endl;
        }
    }
    return 0;
}
