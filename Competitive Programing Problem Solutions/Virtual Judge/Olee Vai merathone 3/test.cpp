#include<bits/stdc++.h>
using namespace std;
vector<char>elements;
vector<vector<char> >adjacent;
bool visited[1001];
bool flag=true;
bool check(char u){
    for(int v=0;v<adjacent[u].size();v++){
        if(visited[adjacent[u][v]]) return false;
    }
    return true;
}
void Back_Tracking(string ch){
    if(ch.length()==elements.size()){
        cout<<ch[0];
        for(int i=1;i<ch.length();i++){
            cout<<" "<<ch[i];
        }
        cout<<'\n';
        flag=false;
        return;
    }
    for(int i=0;i<elements.size();i++){
        char c=elements[i];
        if(!visited[c]){
            if(check(c)){
                visited[c]=true;
                Back_Tracking(ch+c);
                visited[c]=false;
            }
        }
    }
}
int main(){
//    freopen("01.txt","r",stdin);
//    freopen("02.txt","w",stdout);
    int t;
//    cin.ignore();
    scanf("%d",&t);
//    printf("\n");
    getchar();
    while(t--){
        char x,y,z;
        memset(visited,false,sizeof(visited));
        string s;
        stringstream ss;
        getchar();
        getline(cin,s);
        ss.clear();
        ss.str(s);
        while(ss>>x){
            elements.push_back(x);
//            cout<<x;
        }
        sort(elements.begin(),elements.end());
        s.clear();
        adjacent.resize(200);
        getline(cin,s);
        ss.clear();
        ss.str(s);
        while(ss>>x>>y>>z){
            adjacent[x].push_back(z);
//            printf("%c %c %c\n",x,y,z);
        }
        Back_Tracking("");
        if(flag) printf("NO\n");
        flag=true;
        s.clear();
        elements.clear();
        for(int i=0;i<adjacent.size();i++){
            adjacent[i].clear();
        }
        adjacent.clear();
        if(t>0) printf("\n");
    }
    return 0;
}






































/// tri korsi but hoy nai uva 872
//#include<bits/stdc++.h>
//using namespace std;
//vector<char>elements;
//vector<vector<char> >adjacent;
//map<char,bool>visited;
//bool flag=true;
//bool ff=true;
//vector<char>task;
//bool valid(char u){
//    for(int v=0;v<adjacent[elements[u]].size();v++){
//        if(visited[adjacent[u][v]]) return false;
//    }
//    return true;
//}
//void Back_Tracking(int k){
//    if(task.size()==elements.size()){
////        cout<<ch<<'\n';
//        flag=false;
//        for(int i=0;i<task.size();i++){
//            cout<<task[i]<<" ";
//        }
//        cout<<'\n';
//        return;
//    }
//    for(int i=0;i<elements.size();i++){
//        char ch=elements[i];
//        if(!visited[ch]){
//            visited[ch]=true;
//            task.push_back(ch);
//            if(valid(ch)){
//                Back_Tracking(i+1);
//            }
////            else if(ff==false){
//            task.pop_back();
////                ff=true;
////            }
//            visited[ch]=false;
//        }
//    }
//}
//int main(){
//    int t;
//    scanf("%d",&t);
//    printf("\n");
//    while(t--){
//        char x,y,z;
//        string s;
//        stringstream ss;
//        elements.clear();
//        adjacent.clear();
//        adjacent.resize(200);
//        ss.clear();
////        cin.ignore();
//        getchar();
//        getline(cin,s);
//        ss.str(s);
//        while(ss>>x) elements.push_back(x);
////        sort(elements.begin(),elements.end());
////        for(int i=0;i<elements.size();i++){
////            cout<<elements[i]<<" "<<endl;
////        }
//        getchar();
//        getline(cin,s);
//        ss.clear();
//        ss.str(s);
//        while(ss>>x>>y>>z){
//            adjacent[x].push_back(z);
//            printf("%c %c %c\n",x,y,z);
//        }
////        for(int i=0;i<adjacent.size();i++){
////            for(int j=0;j<adjacent[i].size();j++){
////                printf("%c\n",adjacent[i][j]);
////            }
//////        }
//        Back_Tracking(0);
//        if(flag) printf("NO\n");
//        flag=true;
//        if(t>0) printf("\n");
//    }
//    return 0;
//}






















//#include<bits/stdc++.h>
//using namespace std;
//map<int,vector<int> >order;
//map<int,int>indegree;
//map<int,int>taken;
//map<string,int>bijoy;
//map<int,string>joy;
//int n,m,Case=0;
//void T_SORT(){
//    vector<int>task;
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++){
//            if(!taken[j]&&!indegree[j]){
//                taken[j]=1;
//                task.push_back(j);
//                for(int k=0;k<order[j].size();k++){
//                    indegree[order[j][k]]--;
//                }
//                break;
//            }
//        }
//    }
//    cout<<"Case #"<<++Case<<": Dilbert should drink beverages in this order: ";
//    int i;
//    for(i=0;i<task.size()-1;i++){
//        cout<<joy[task[i]]<<" ";
//    }
//    cout<<joy[task[i]]<<"."<<endl<<endl;
//    task.clear();
//}
//int main(){
//    string s;
//    while(cin>>n){
//        for(int i=1;i<=n;i++){
//            cin>>s;
//            bijoy[s]=i;
//            joy[i]=s;
//        }
//        cin>>m;
//        for(int i=1;i<=m;i++){
//            string a,b;
//            cin>>a>>b;
//            indegree[bijoy[b]]++;
//            order[bijoy[a]].push_back(bijoy[b]);
//        }
//        T_SORT();
//        for(int i=1;i<=n;i++){
//            order[i].clear();
//        }
//        indegree.clear();
//        taken.clear();
//        bijoy.clear();
//        joy.clear();
//    }
//    return 0;
//}








































































///124-UVA
//#include<bits/stdc++.h>
//using namespace std;
//vector<char>elements;
//vector<vector<char> >adjcent;
//map<char,bool>visited;
//
//bool valid(int u){
//    for(int v=0;v<adjcent[elements[u]].size();v++){
//        if(visited[adjcent[elements[u]][v]])
//        return false;
//    }
//    return true;
//}
//void Back(string ch){
//    if(ch.length()==elements.size()){
//        cout<<ch<<endl;
//        return;
//    }
//    for(int i=0;i<elements.size();i++){
//        if(!visited[elements[i]]){
//            visited[elements[i]]=true;
//            if(valid(i)) Back(ch+elements[i]);
//            visited[elements[i]]=false;
//        }
//    }
//}
//int main(){
//    char x,y;
//    string s;
//    stringstream ss;
//    bool flag=false;
//    while(getline(cin,s)){
//        if(flag) cout<<'\n';
//        flag=true;
//        elements.clear();
//        adjcent.clear();
//        adjcent.resize(150);
//        ss.clear();
//        ss.str(s);
//        while(ss>>x) elements.push_back(x);
//        sort(elements.begin(),elements.end());
//        getline(cin,s);
//        ss.clear();
//        ss.str(s);
//        while(ss>>x>>y) adjcent[x].push_back(y);
//        Back("");
//    }
//    return 0;
//}
