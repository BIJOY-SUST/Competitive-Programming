#include<bits/stdc++.h>
using namespace std;
int n,m,NO=0;
map<int,vector<int> >order;
map<int,int>indegree;
map<int,int>taken;
map<string,int>pic;
map<int,string>pic2;
void T_SORT(){
    vector<int>task;
    //bool flag=true;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!taken[j] && !indegree[j]){
                taken[j]=1;
                task.push_back(j);
                for(int k=0;k<order[j].size();k++){
                    indegree[order[j][k]]--;
                }
                break;
            }
        }
        //if(j==n+1) flag=false;
    }
    cout<<"Case #"<<++NO<<": Dilbert should drink beverages in this order: ";
    int i;
    for(i=0;i<task.size()-1;i++){
        cout<<pic2[task[i]]<<" ";
    }
    cout<<pic2[task[i]]<<"."<<endl<<endl;
    task.clear();
    //if(flag==true){
        //vector<int>::iterator it;
        //cout<<"Case #"<<++NO<<": Dilbert should drink beverages in this order: ";
        //for(it=task.begin();it!=task.end()-1;it++){
            //cout<<pic2[*it]<<" ";
        //}
        //cout<<pic2[*it]<<"."<<endl;
        //task.clear();
    //}
   // else{
       // cout<<"This is no solution"<<endl;
        //task.clear();
   // }
}

int main(){
    string s;
    while(cin>>n){
//        getchar();
        int c=0;
        for(int i=1;i<=n;i++){
            //getline(cin,s);
            cin>>s;
            pic[s]=++c;
            pic2[c]=s;
        }
        cin>>m;
        for(int i=1;i<=m;i++){
            string u,v;
            cin>>u>>v;
            indegree[pic[v]]++;
            order[pic[u]].push_back(pic[v]);
        }
        T_SORT();
        for(int i=1;i<=n;i++){
            order[i].clear();
        }
        indegree.clear();
        taken.clear();
        pic.clear();
        pic2.clear();
    }
    return 0;
}


