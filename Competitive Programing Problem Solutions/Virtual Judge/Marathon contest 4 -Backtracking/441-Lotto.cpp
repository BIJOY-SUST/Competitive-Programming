/*______________________________________________
 !                   BIJOY                      !
 !               CSE-25th Batch                 !
 !Shahjalal University of Science and Technology!
 !______________________________________________!
*/
#include<bits/stdc++.h>
//#define pi             3.14159265358979323846264338328
//#define pi             acos(-1)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define mx             1000001
//#define mod            1000000007
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
using namespace std;
vector<int>elements;
bool flag[10001];
vector<int>ans;
void B_T(int len){
    if(ans.size()==6){
        cout<<ans[0];
        for(int i=1;i<ans.size();i++) cout<<" "<<ans[i];
        cout<<endl;
        return;
    }
    for(int i=len;i<elements.size();i++){
        if(flag[elements[i]]==0){
            flag[elements[i]]=1;
            ans.push_back(elements[i]);
            B_T(i+1);
            flag[elements[i]]=0;
            ans.pop_back();
        }
    }
}
int main(){
//    freopen("01.txt","r",stdin);
//    freopen("02.txt","w",stdout);
    int n;
    bool i=false;
    char x;
//    string s;
    while(scanf("%d",&n)){
        if(n==0) break;
        else if(n!=0&&i) printf("\n");
        i=true;
        for(int i=0;i<n;i++){
            int k;
            scanf("%d",&k);
            elements.push_back(k);
        }
//        stringstream ss;
//        getline(cin,s);
//        ss.clear();
//        ss.str(s);
//        while(ss>>x) elements.push_back(x);
//        for(int i=0;i<elements.size();i++){
//            cout<<elements[i]<<'\n';
//        }
        memset(flag,0,sizeof(flag));
        B_T(0);
        elements.clear();
        ans.clear();
    }
    return 0;
}
