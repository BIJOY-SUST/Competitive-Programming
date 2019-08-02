#include<bits/stdc++.h>

using namespace std;

///Faster I/O


#define nl              '\n'
#define sf              scanf
#define pf              printf
#define F               first
#define S               second
#define pb              push_back
#define eb              emplace_back
#define ui              unsigned int
#define ll              long long int
#define ull             unsigned long long int
#define vi              vector<int>

#define fast            ios_base::sync_with_stdio(false),cin.tie(NULL)


const int mxn       = 5e6+10;
const int inf       = 0x3f3f3f3f;



const int N=mxn;
struct aho_corasick
{
    bool is_end[N];
    int link[N]; ///A suffix link for a vertex p is a edge that points to
    int psz; ///tracks node numbers of the trie
    map<char, int> to[N]; ///tracks the next node
    vi ending[N]; ///ending[i] stores the indexes of patterns which ends
    vi oc[N]; ///oc[i] stores ending index of all occurrences of pattern[i]
    int cnt[N],path[N],ind[N],len;///for number of occurrences
    void clear()
    {
        for(int i = 0; i < psz; i++)
            is_end[i] = 0,cnt[i]=0,path[i]=0, ind[i]=0,link[i] = 0, to[i].clear(),ending[i].clear(),oc[i].clear();
        psz = 1;
        is_end[0] = 1;
        len=0;
    }
    aho_corasick()
    {
        psz = N - 2;
        clear();
    }
    void add_word(string s,int idx)
    {
        int u = 0;
        for(char c: s)
        {
            if(!to[u].count(c)) to[u][c] = psz++;
            u = to[u][c];
        }
        is_end[u] = 1;
        ending[u].eb(idx);
        ind[idx]=u;
//        debug(s,idx,u);
    }
    void populate(int cur)
    {
        for(auto occ: ending[link[cur]]){
            ending[cur].eb(occ);
//            debug(cur,occ);
        }

    }
    void push_links()
    {
        queue<int> q;
        int u, v, j;
        char c;
        q.push(0);
        link[0] = -1;
        while(!q.empty())
        {
            u = q.front();
            q.pop();
            for(auto it: to[u])
            {
                v = it.second;
                c = it.first;
                j = link[u];
                while(j != -1 && !to[j].count(c)) j = link[j];
                if(j != -1) link[v] = to[j][c];
                else link[v] = 0;
                q.push(v);
                populate(v);
                path[len++]=v;
//                debug(u,v,c,j,link[u],link[v]);
            }
        }
    }
    void populate(vi &en, int cur)
    {
        for(auto idx: en)
        {
            oc[idx].eb(cur);
//            debug(idx,cur);
        }
    }
    void traverse(string s)
    {
        int n=s.size();
        int cur=0;///root
        for(int i=0; i<n; i++)
        {
            char c=s[i];
            while(cur!=-1 && !to[cur].count(c)) cur=link[cur];
            if(cur!=-1) cur=to[cur][c];
            else cur=0;
            populate(ending[cur],i);
            cnt[cur]++;
//            debug(c,cur,cnt[cur]);
        }
        for(int i=len-1; i>=0; i--) cnt[link[path[i]]]+=cnt[path[i]];
    }
};
aho_corasick t;
string p[N];
int kk[N];
string s;

int main()
{
    fast;
    int i,j,k,n,m;
    t.clear();
    cin>>m;
    for(i=0; i<m; i++)
    {
        cin>>p[i];
        t.add_word(p[i],i);
    }
//    getchar();
    t.push_links();
    cin>>n;
    for(i=0;i<n;i++){
        cin>>s;
        t.traverse(s);

    }
//    cout<<s<<nl;
    for(i=0; i<m; i++)
    {
        cout<<t.oc[i].size()<<nl;
    }

    return 0;
}
/*


*/


