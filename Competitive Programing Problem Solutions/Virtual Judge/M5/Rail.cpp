#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    while(cin>>N){
        getchar();
        if(N==0)break;
        list<int>d;
        bool flag = true;
        while(flag==true){
            d.clear();
            int k=0,e;
            for(int i=1;i<=N;i++){
                cin>>e;
                if(e==0){
                    flag = false;
                    cout<<endl;
                    break;
                }
                while(k<N&&k!=e){
                    if(!d.empty()&&d.back()==e)break;
                    k++;
                    d.push_back(k);
                }
                if(d.back()==e){
                    d.pop_back();
                }
            }
            if(flag==true&&d.empty()) cout<<"Yes"<<endl;
            else if(flag==true&&!d.empty()) cout<<"No"<<endl;
        }
    }
    return 0;
}
/*
5
1 2 3 4 5
5 4 1 2 3
0
6
6 5 4 3 2 1
0
4
3 2 4 1
0
0
*/
