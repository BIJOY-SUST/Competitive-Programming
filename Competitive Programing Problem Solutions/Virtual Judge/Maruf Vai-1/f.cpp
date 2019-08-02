#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,c=0;
    vector<int>s_num;
    map<int,string>s_name;
    string s;
    cin>>N;
    for(int i=0;i<N;i++){
        s_num.push_back(i);
        cin>>s;
        s_name[i]=s;
    }
    for(char i='a';i<='z';i++){
        for(int j=0;j<N;j++){
            if(binary_search(s_name[s_num[j]].begin(),s_name[s_num[j]].end(),i)){

            }
            if(j==N-1){
                c++;
            }
            else{
                break;
            }
        }
    }
    cout<<c<<endl;
    return 0;
}


