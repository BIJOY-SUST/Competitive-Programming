#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,e,p;
    while(cin>>n){
        if(n==0)break;
        cin>>e;
        vector<int>edges[10000];
        for(int i=0;i<e;i++){
            int x,y;
            cin>>x>>y;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        int n = 0;
        queue<int>q;
        int f=0;
        int color[10000];
        memset(color,-1,sizeof(color));
        color[n]=0;
        q.push(n);

        while(!q.empty())
        {
            p=q.front();
            q.pop();
            int vsize=edges[p].size();
            for(int i=0;i<vsize;i++)
            {
                int v=edges[p][i];
                if(color[v]==-1)
                {
                    color[v]=1-color[p];
                    q.push(v);
                }
                else
                {
                    if(color[v]==color[p]){
                        f=1;
                        break;
                    }
                }
            }
            if(f==1)
                break;
        }
        f==1?cout<<"NOT BICOLORABLE"<<endl:cout<<"BICOLORABLE"<<endl;
    }

    return 0;
}
