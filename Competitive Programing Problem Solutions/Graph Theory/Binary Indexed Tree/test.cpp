///// An easy solving by Binary Index Tree
//#include<bits/stdc++.h>
//#define mx 1000001
//using namespace std;
//char elements[mx];
//int BITree[3*mx];
//int N;
//int query(int index){
//    int sum=0;
////    index=index+1;
//    while(index>0){
//        sum+=BITree[index];
//        index-=index&(-index);
//    }
//    return sum;
//}
//
//void update(int index,int value){
////    index=index+1;
//    while(index<=N){
//        BITree[index]+=value;
//        index+=index&(-index);
//    }
//}
//void update_range(int u,int v){
//    update(u,1);
//    update(v+1,-1);
//}
////void constructBITree(){
////    for(int i=1;i<=N;i++){
////        BITree[i]=0;
////    }
////    for(int i=0;i<N;i++){
////        update(i+1,elements[i]-'0');
////    }
////}
//int main(){
//    int t;
//    scanf("%d",&t);
//    for(int i=1;i<=t;i++){
//        printf("Case %d:\n",i);
//        memset(BITree,0,sizeof(BITree));
//        scanf("%s",&elements);
//        N=strlen(elements);
////        for(int i=0;i<N;i++){
////            printf("%c ",elements[i]);
////        }
////        constructBITree();
//        int m;
//        scanf("%d",&m);
//        while(m--){
//            getchar();
//            char ch;
//            scanf("%c",&ch);
//            if(ch=='I'){
//                int x,y;
//                scanf("%d %d",&x,&y);
//                update_range(x,y);
//            }
//            else{
//                int x;
//                scanf("%d",&x);
//                printf("%d\n",((elements[x-1]-'0')^(query(x)%2)));
//            }
//        }
//    }
//    return 0;
//}
