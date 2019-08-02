#include<bits/stdc++.h>
using namespace std;
int main(){
    char arr[301][301];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
       scanf("%s",&arr[i]);
    }
    char a=arr[0][0],b=arr[0][1];
    bool flag = true;
    if(a==b) flag = false;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j||j==n-i-1){
                if(arr[i][j]!=a){
                    flag = false;
                }
            }
            else if(arr[i][j]!=b){
                flag = false;
            }
        }
        if(flag == false){
            break;
        }
    }
    flag==true?cout<<"YES":cout<<"NO"<<"\n";
    return 0;
}
