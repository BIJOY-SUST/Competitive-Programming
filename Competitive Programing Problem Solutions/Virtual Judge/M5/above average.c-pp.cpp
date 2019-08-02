#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int N,sum=0;
        cin>>N;
        int ara[1001];
        for(int i=0;i<N;i++){
            cin>>ara[i];
            sum+=ara[i];
        }
        int c=0;
        float average = (float)sum/N;
        for(int i=0;i<N;i++){
            if(ara[i]>average){
                c++;
            }
        }
        float ans = (float)(c*100)/N;
        printf("%.3f",ans);
        cout<<"%"<<endl;
    }
    return 0;
}
