#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        bool flag=true;
        int N,arr[1001];
        vector<int>v1,v2,v3;
        cin>>N;
        for(int i=0;i<N;i++){
            cin>>arr[i];
            v1.push_back(arr[i]);
        }
        v3=v2=v1;
        int k=arr[0];
        for(int i=1;i<N;i++){
            if(k!=arr[i]) flag=false;
        }
        if(flag==true) cout<<"neutral"<<endl;



            if(arr[i]==arr[i+1]){

            }
            if(z==N){

                flag=false;
                break;
            }
            if(arr[i]<=arr[i+1]){
                x++;
            }
            if(x==N) {
                cout<<"allGoodDays"<<endl;
                flag=false;
                break;
            }
            if(arr[i]>=arr[i+1]){
                y++;
            }

            if(y==N) {
                cout<<"allBadDays"<<endl;
                flag=false;
                break;
            }
        }
        if(flag==false) continue;
        int kin[1001],d=0,c=0;
        for(int i=1;i<N-1;i++){
            if(arr[i]>arr[i-1]&&arr[i]>arr[i+1]){
                kin[c]=i+1;
                c++;
            }
        }
        for(int i=0;i<c-1;i++){
            int j=kin[i+1]-kin[i]-1;
            if(j>=d){
                d=j;
            }
        }
        if(c>=2) cout<<d<<endl;
        else cout<<"none"<<endl;
    }
    return 0;
}

