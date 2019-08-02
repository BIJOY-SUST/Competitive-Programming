#include<bits/stdc++.h>
using namespace std;
int n;
//vector<int>v;
int input[100];///-102 1 134565589 134565589 -102 66666668 134565589 66666668 -102 1 -2
void compress(){
    map<int,int>element;
    //sort(input,input+n);
    int assign=0,c=0,compressed[n];
    for(int i=0;i<n;i++){
        int x=input[i];
        if(element.find(x)==element.end()){///x not yet compressed
            element[x]=assign;
            printf("Mapping %d with %d\n",x,assign);
            assign++;
        }
        x=element[x];
        compressed[c++]=x;
    }
    printf("Compressed Array:\n");
    for(int i=0;i<n;i++){
        printf("%d ",compressed[i]);
    }
    printf("\n");
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&input[i]);
        //v.push_back(input[i]);
    }
    compress();
    return 0;
}
