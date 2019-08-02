#include<bits/stdc++.h>
using namespace std;
vector<vector<bool> >A(10001,vector<bool>(26,0));
vector<vector<bool> >B(10001,vector<bool>(26,0));
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    char ch;
//    string s;
//    set<char>hh[10010];
    getchar();
    for(int i=0;i<n;i++){
        while(ch=getchar()){
//            scanf("%c",&ch);
            if(ch == '\n') break;
            int d=ch-'A';
            A[i][d]=true;
        }
    }
    for(int i=0;i<m;i++){
        while(ch=getchar()){
//            scanf("%c",&ch);
            if(ch == '\n') break;
            int d=ch-'A';
            B[i][d]=true;
        }
    }
//    set<char>sss;
    int sz1,sz2,cnt=0;
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int cnt=0;
            for(char k=0;k<26;k++){
                if(!(A[i][k] || B[j][k])){
                    break;
                }
                cnt++;
            }
            if(cnt==26) ans++;

        }
    }
    printf("%d\n",ans);
    return 0;
}
/*

*/

