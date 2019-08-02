#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d\n\n",&t);
//    cin>>t;
    map<string,int>m;
    set<string>v;
    while(t--)
    {
        string c;
        int no=0;
        getchar();
        while(getline(cin,c)){

                if(c.length()==0) break;
                //if(c=="Willow")
                //break;
        v.insert(c);
        //if(m[c]==0) m[c]=1;
        //else m[c]++;
        m[c]++;
        no++;
        }
        //int s=v.size();

        //cout<<s<<endl;

        //sort(v.begin(),v.end());
        //cout<<v[0]<<" ";
        //printf("%0.4f\n",(double)(m[v[0]]/(s*1.0))*100);
        //for(int i=1;i<v.size();i++){
        for(__typeof(v.begin()) it=v.begin();it!=v.end();it++){
            //if(v[i-1]!=v[i]){
            cout<<*it<<" ";
            printf("%0.4f\n",(double)m[*it]/(double)no*100.0);
        }
        v.clear();
        m.clear();
        if(t>0)
        cout<<endl;
        }
    return 0;
}

