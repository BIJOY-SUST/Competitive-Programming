#include<bits/stdc++.h>
using namespace std;
vector<int>elements;
vector<int>BITree;
int N;
int getSum(int index){
    int sum=0;
    index=index+1;
    while(index>0){
        sum+=BITree[index];
        index-=index&(-index);
    }
    return sum;
}
int rangeQuery(int u,int v){
    return getSum(v)-getSum(u-1);
}
void updateBIT(int index,int value){
    index=index+1;
    while(index<=N){
        BITree[index]+=value;
        index+=index&(-index);
    }
}
void constructBITree(){
    for(int i=1;i<=N;i++){
        BITree.push_back(0);
    }
    for(int i=0;i<N;i++){
        updateBIT(i,elements[i]);
    }
}
int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        int k; scanf("%d",&k);
        elements.push_back(k);///2 1 1 3 2 3 5 6 7 8 9
    }
    constructBITree();
//    int m;
//    scanf("%d",&m);
    printf("Sum of array....is %d\n",getSum(5));
//    int x,y;
//    scanf("%d %d",&x,&y);
    updateBIT(3,6);
    printf("Sum of array....is %d\n",getSum(5));
//    int h,k;
//    scanf("%d %d",&h,&k);
    printf("Sum of array....is %d\n",rangeQuery(0,6));

    return 0;
}
