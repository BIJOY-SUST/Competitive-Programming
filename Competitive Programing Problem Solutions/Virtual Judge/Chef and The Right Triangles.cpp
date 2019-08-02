#include<bits/stdc++.h>

using namespace std;
int main(){

    int N,x1,x2,x3,y1,y2,y3,count=0;
    cin>>N;
    while(N--){
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    if(((y2-y1)*(y3-y1))==-((x2-x1)*(x3-x1))){
        count++;
    }
    else if(((y1-y2)*(y3-y2))==-((x1-x2)*(x3-x2))){
        count++;
    }
    else if(((y1-y3)*(y2-y3))==-((x1-x3)*(x2-x3))){
        count++;
    }
    }
    cout<<count<<endl;

    return 0;

}
