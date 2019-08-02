#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>input;///-102 1 134565589 134565589 -102 66666668 134565589 66666668 -102 1 -2
vector<int>sort_input;
void compress(){
    int c=0,compressed[n];
    sort(sort_input.begin(),sort_input.end());
    sort_input.erase(unique(sort_input.begin(),sort_input.end()),sort_input.end());
    vector<int>::iterator it;
    for(it=input.begin();it!=input.end();it++){
        //cout<<*it<<endl;
        for(int i=0;i<sort_input.size();i++){
            if(sort_input[i]==*it){
                compressed[c++]=i;
                break;
            }
        }
        //int x = distance(input.begin(), find(input.begin(), input.end(), *it));
        //cout<<x<<endl;

    }
    printf("Compressed Array:\n");
    for(int i=0;i<n;i++){
        printf("%d ",compressed[i]);
    }
    printf("\n");
}
int main(){
    int k;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k;
        input.push_back(k);
        sort_input.push_back(k);
    }
    compress();
    return 0;
}
