#include<bits/stdc++.h>
using namespace std;
#define mx 1005
#define LL long long
#define MOD 1000007
#define right rr
#define left ll
int n, m;
char a[mx], b[mx],c[mx],d[mx];
pair<int, int> dp[mx][mx];
int aRight[mx][26];
int bRight[mx][26];

pair<int, int> rec(int l, int r)
{
    if(l==n || r==m) return {0, 1};
    pair<int, int> &ret = dp[l][r];
    if(ret.first != -1) return ret;
    ret = make_pair(0, 1);

    for(int i = 0; i<26; i++)
    {
        int aR = aRight[l][i];
        int bR = bRight[r][i];
        if(aR == -1 || bR == -1){
            continue;
        }
        cout<<"before ";
        cout<<c[aR]<<" "<<d[bR]<<" ";
        cout<<"ret "<<ret.first<<" "<<ret.second<<endl<<endl;
        pair<int, int> now = rec(aR+1, bR+1);
        cout<<"after ";
        cout<<c[aR]<<" "<<d[bR]<<" ";
        cout<<"ret "<<ret.first<<" "<<ret.second<<" ";
        cout<<"now "<<now.first<<" "<<now.second<<'\n';
        if(ret.first < now.first+1) ret.first = now.first+1, ret.second = now.second,cout<<"A ";
        else if(ret.first == now.first+1) ret.second = (ret.second + now.second) % MOD,cout<<"B ";
        cout<<"ret "<<ret.first<<" "<<ret.second<<endl;

    }

    return ret;
}


int main()
{
    int t, tst = 1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s %s", a, b);
        n = strlen(a);
        m = strlen(b);
        for(int i = 0; i<n; i++) c[i]=a[i],a[i] -= 'a';
        for(int j = 0; j<m; j++) d[j]=b[j],b[j] -= 'a';
        for(int i = 0; i<=n; i++)
            for(int j = 0; j<26; j++)
                aRight[i][j] = -1;
        for(int i = 0; i<=m; i++)
            for(int j = 0; j<26; j++)
                bRight[i][j] = -1;
        for(int i = n-1; i>=0; i--)
        {
            for(int j = 0; j<26; j++)
                aRight[i][j] = aRight[i+1][j];
            aRight[i][a[i]] = i;
        }
        for(int i = m-1; i>=0; i--)
        {
            for(int j = 0; j<26; j++)
                bRight[i][j] = bRight[i+1][j];
            bRight[i][b[i]] = i;
        }
        for(int i = 0; i<=n; i++)
            for(int j = 0; j<=m; j++)
                dp[i][j].first = -1;
        int ans = rec(0, 0).second;
        printf("Case %d: %d\n", tst++, ans);
    }
    return 0;
}
/*
jmqhdq
hbdjmq
*/
