using namespace std;
ll MPG;
class node{
public:
    ll endmark;
    node *next[30];
    node(){
        endmark = 0;
        for(int i=0;i<30;i++){
            next[i]=NULL;
        }
    }
};
node *root;
void insert(string s){
    node *current_node=root;
    for(int i=0;i<s.length();i++){
        int id = s[i]-'a';
        if(current_node->next[id]==NULL){
            current_node->next[id]=new node();
        }
        current_node=current_node->next[id];
        current_node->endmark=current_node->endmark+1;
//        MPG=max(MPG,current_node->endmark*(i+1));
    }
}
void dfs(node *current_node,int endmark){
    if(current_node==NULL) return;
    if(current_node->endmark==1){
        MPG+=endmark;
        return;
    }
    for(int i=0;i<26;i++){
        if(current_node->next[i]!=NULL){
            dfs(current_node->next[i],endmark+1);
        }
    }
}
void del(node *current_node){
    for(int i=0;i<26;i++){
        if(current_node->next[i])
            delete(current_node->next[i]);
    }
    delete(current_node);
}
int main(){
    int T,N;
    cin>>T;
    while(T--){
        MPG=0;
        string s;
        root = new node();
        cin>>N;
        for(int i=0;i<N;i++){
            cin>>s;
            insert(s);
        }
        node *current_node=root;
        dfs(current_node,0);
        cout<<MPG<<endl;
        del(root);
    }
    return 0;
}
