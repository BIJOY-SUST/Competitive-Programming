#include<bits/stdc++.h>
using namespace std;
int s[1000000+1];
int ss[1000000+1];
int main(){
    long long int N,n,i,j,k;
    cin>>N;
    getchar();
    while(N--){
        memset(s,0,sizeof(s));
        memset(ss,-1,sizeof(ss));
        cin>>n;
        for(i=0;i<n;i++){
            cin>>s[i];
        }
        long long int c=0,d=0;
        for(int i=0;i<n-1;i++){
            for(int j=i;j<n;j++){
                if(ss[s[j]]==-1){
                    ss[s[j]]=0;
                    c++;
                    if(c>d){
                        d=c;
                    }
                }
                else{
                    break;
                }
            }
            c=0;
            memset(ss,-1,sizeof(ss));
        }
        cout<<d<<endl;
  }
    return 0;
}




        /*for(j=0;j<n;j++){
            if(ss[s[j]]==-1){
                ss[s[j]]=0;
                c++;
                if(d<c){
                    d=c;
                }
            }
            else if(ss[s[j]]==0){
                c=1;
                memset(ss,-1,sizeof(ss));
                ss[s[j]]=0;
            }
        }
        cout<<d<<endl;*/

