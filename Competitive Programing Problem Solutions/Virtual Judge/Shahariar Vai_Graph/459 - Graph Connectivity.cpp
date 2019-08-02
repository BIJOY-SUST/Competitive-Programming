/*______________________________________________
 !                   BIJOY                      !
 !               CSE-25th Batch                 !
 !Shahjalal University of Science and Technology!
 !______________________________________________!
*/
#include<bits/stdc++.h>
using namespace std;
int Parent[100],Rank[100];
int find_par(int x){
    if(Parent[x]!=x) Parent[x]=find_par(Parent[x]);
    return Parent[x];
}
int main(){
    int T;
    string s;
    scanf("%d\n\n",&T);
    for(int j=1;j<=T;j++){
        getline(cin,s);
        int n,M_C_S;
        n=s[0]-'A'+1;
        M_C_S=n;
        for(int i=0;i<n;i++){
            Parent[i]=i;
            Rank[i]=0;
        }
        while(1){
            if(!getline(cin,s)||s.empty()) break;
            int u=s[0]-'A';
            int v=s[1]-'A';
            int pu=find_par(u);
            int pv=find_par(v);
            if(pu!=pv){
                M_C_S--;
                if(Rank[pu]>Rank[pv]) Parent[pv]=pu;
                else{
                    Parent[pu]=pv;
                    if(Rank[pu]==Rank[pv]) Rank[pv]++;///if use Rank[pv]++ than also AC... But Better Rank[pv]++...because we set parent[pu]=pv...so
                }
            }
        }
        if(j!=1) printf("\n");
        printf("%d\n",M_C_S);
    }
    return 0;
}
