#include<bits/stdc++.h>
#define mx 1000001
using namespace std;
bool mark[mx];
vector<int>prime;
//list<int>st;
int mp[151];
//int xxx[mx];
void sieve(){
    memset(mark,true,sizeof(mark));
    mark[0]=mark[1]=false;
    for(int i=4;i<=mx;i+=2) mark[i]=false;
    for(int i=3;i<=(int)sqrt(mx);i+=2)if(mark[i]){
        for(int j=i*i;j<=mx;j+=2*i) mark[j]=false;
    }
    prime.push_back(2);
    for(int i=3;i<=mx;i+=2) if(mark[i]) prime.push_back(i);
}
int main(){
//    freopen("111.txt","r",stdin);
//    freopen("112.txt","w",stdout);
    sieve();
//    for(int i=0;i<500;i++){
//        cout<<i+1<<" "<<prime[i]<<'\n';
//    }
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    int t;
    scanf("%d",&t);
    while(t--){
        int L,U;
        scanf("%d %d",&L,&U);
        int k,d=0,ans=0;
        bool flag=true;
        memset(mp,0,sizeof(mp));
//        int low=int(lower_bound(prime.begin(),prime.end(),L)-prime.begin());
//        int up=int(upper_bound(prime.begin(),prime.end(),U)-prime.begin());
//        memset(xxx,0,sizeof(xxx));
//        cout<<low<<" "<<up<<endl;
        for(int i=L;i<=U;i++){
            if(flag==true&&mark[i]==true){
//                    cout<<i<<endl;
                k=i;
                flag=false;
                continue;
            }

            if(mark[i]==true){
//                    cout<<i-k<<endl;
                //mp[i-k]++;
//                int tt=prime[i]-prime[i-1];
//                cout<<d<<" "<<++mp[i-k]<<" "<<k<<" "<<i<<endl;
                if(++mp[i-k]>d){
//                        cout<<mp[i-k]<<" "<<k<<" "<<i<<endl;
//                    if(d==mp[i-k]){
//                        xxx[i-k]++;
//                        continue;
//                    }
                    d=mp[i-k];
                    ans=i-k;
//                    st.push_back(ans);
//                    cout<<ans<<endl;
                }
                k=i;
            }
        }
        int c=0;
        for(int i=1;i<=150;i++){
            if(mp[i]==d){
                c++;
                if(c>1) break;
            }
        }
//        if(st.size()==1){
//            cout<<"The jumping chamion is "<<st.front()<<'\n';
//            continue;
//        }
//        st.unique();
//        st.sort();
//        cout<<st.size()<<endl;
        //if((st.size()==0)||(st.size()==1)) cout<<"No jumping chamion\n";
        if(c>1||d==0) printf("No jumping champion\n");//cout<<"No jumping champion\n";
        else printf("The jumping champion is %d\n",ans);//cout<<"The jumping champion is "<<ans<<'\n';
           //printf("%d\n",ans);st.clear()
    }
    return 0;
}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//#include<bits/stdc++.h>
//#define mx 1000001
//using namespace std;
//bool mark[mx];
//vector<int>prime;
////list<int>st;
//int mp[151];
////int xxx[mx];
//void sieve(){
//    memset(mark,true,sizeof(mark));
//    mark[0]=mark[1]=false;
//    for(int i=4;i<=mx;i+=2) mark[i]=false;
//    for(int i=3;i<=(int)sqrt(mx);i+=2)if(mark[i]){
//        for(int j=i*i;j<=mx;j+=2*i) mark[j]=false;
//    }
//    prime.push_back(2);
//    for(int i=3;i<=mx;i+=2) if(mark[i]) prime.push_back(i);
//}
//int main(){
////    freopen("111.txt","r",stdin);
////    freopen("112.txt","w",stdout);
//    sieve();
////    for(int i=0;i<500;i++){
////        cout<<i+1<<" "<<prime[i]<<'\n';
////    }
////    ios_base::sync_with_stdio(false);
////    cin.tie(NULL);
//    int t;
//    scanf("%d",&t);
//    while(t--){
//        int L,U;
//        scanf("%d %d",&L,&U);
//        int k,d=0,ans=0;
////        bool flag=true;
//        memset(mp,0,sizeof(mp));
//        int low=int(lower_bound(prime.begin(),prime.end(),L)-prime.begin());
//        int up=int(upper_bound(prime.begin(),prime.end(),U)-prime.begin());
////        memset(xxx,0,sizeof(xxx));
////        cout<<low<<" "<<up<<endl;
//        for(int i=low+1;i<up;i++){
////            if(flag==true&&mark[i]==true){
//////                    cout<<i<<endl;
////                k=i;
////                flag=false;
////                continue;
////            }
//
////            if(mark[i]==true){
////                    cout<<i-k<<endl;
//                //mp[i-k]++;
//                int tt=prime[i]-prime[i-1];
////                cout<<d<<" "<<++mp[i-k]<<" "<<k<<" "<<i<<endl;
//                if(++mp[tt]>d){
////                        cout<<mp[i-k]<<" "<<k<<" "<<i<<endl;
////                    if(d==mp[i-k]){
////                        xxx[i-k]++;
////                        continue;
////                    }
//                    d=mp[tt];
//                    ans=tt;
////                    st.push_back(ans);
////                    cout<<ans<<endl;
//                }
////                k=i;
////            }
//        }
//        int c=0;
//        for(int i=1;i<=150;i++){
//            if(mp[i]==d){
//                c++;
//                if(c>1) break;
//            }
//        }
////        if(st.size()==1){
////            cout<<"The jumping chamion is "<<st.front()<<'\n';
////            continue;
////        }
////        st.unique();
////        st.sort();
////        cout<<st.size()<<endl;
//        //if((st.size()==0)||(st.size()==1)) cout<<"No jumping chamion\n";
//        if(c>1||d==0) printf("No jumping champion\n");//cout<<"No jumping champion\n";
//        else printf("The jumping champion is %d\n",ans);//cout<<"The jumping champion is "<<ans<<'\n';
//           //printf("%d\n",ans);st.clear()
//    }
//    return 0;
//}
