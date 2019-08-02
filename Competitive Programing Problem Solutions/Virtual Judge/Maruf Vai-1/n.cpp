#include<bits/stdc++.h>
using namespace std;
int main(){
    int r,c;
    string s;
    cin>>r>>c;
   // vector<string>v;
    //for(int i=0;i<r;i++){
        //cin>>s;
        //v.push_back(s);
    //}
    char v[r][c];
    for(int i=0;i<r;i++){
        cin>>v[i];
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            bool flag = true;
            for(int h=0;h<r;h++){
                if(v[h][j]==v[i][j]&&h!=i){
                    flag  = false;
                    //cout<<h<<" "<<j<<endl;
                }
            }
            for(int h=0;h<c;h++){
                if(v[i][h]==v[i][j]&&h!=j){
                    flag  = false;
                    //cout<<j<<" "<<h<<endl;
                }
            }
            if(flag == true){
                //cout<<i<<" "<<j<<endl;
                cout<<v[i][j];
            }
        }
    }
    cout<<endl;
    return 0;
}
