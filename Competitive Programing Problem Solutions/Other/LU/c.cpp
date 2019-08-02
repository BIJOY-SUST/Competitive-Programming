#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        while(m--){
            int p,q,red=0,green=0;
            scanf("%d %d",&p,&q);
            if(p==q){
                if(p%2==0) green++;
                else red++;
            }
            else if(q-p==1){
                green++;
                red++;
            }
            else if(q-p==2){
                if(p%2==0){
                    green=2;
                    red=1;
                }
                else{
                    green=1;
                    red=2;
                }
            }
            else{
                p%2==0?green++:red++;
                q%2==0?green++:red++;
                int k=q-p-1;
                int h=k/2;
                if(p%2==0){
                    green+=h;
                    red+=k-h;
                }
                else{
                    red+=h;
                    green+=k-h;
                }
            }
            //for(int i=p;i<=q;i++){
                //if(i%2==0) green++;
                //else red++;
           // }
            printf("%d %d\n",red,green);
        }
    }
    return 0;
}
