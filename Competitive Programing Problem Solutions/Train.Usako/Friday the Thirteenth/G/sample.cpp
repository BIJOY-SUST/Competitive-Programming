/*
ID: bsbijoy1
LANG: C++
TASK: friday
*/
#include<bits/stdc++.h>

using namespace std;

int main(){
    //freopen("friday.in","r",stdin);
    //freopen("friday.out","w",stdout);
    int n,day_no=1;
    cin>>n;
    vector<int>day_name;
    map<int,long long>day_count;

    for(int i=0;i<7;i++){
        day_name.push_back(i);
        day_count[i] = 0;
    }
    for(int i=1900;i<=1900+n-1;i++){
        for(int j=1;j<=12;j++){
            if(j==1||j==3||j==5||j==7||j==8||j==10||j==12){
                for(int k=1;k<=31;k++){
                    day_no=day_no+1;
                    day_no=day_no%7;
                    if(k==13){
                        day_count[day_no]++;

                    }
                }
            }
            else if(j!=2){
                for(int k=1;k<=30;k++){
                    day_no=day_no+1;
                    day_no=day_no%7;
                    if(k==13){
                        day_count[day_no]++;
                    }
                }
            }
            else{
                if(i%400==0||(i%100!=0&&i%4==0)){
                    for(int k=1;k<=29;k++){
                        day_no=day_no+1;
                        day_no=day_no%7;
                        if(k==13){
                            day_count[day_no]++;
                        }
                    }
                }
                else{
                    for(int k=1;k<=28;k++){
                        day_no=day_no+1;
                        day_no=day_no%7;
                        if(k==13){
                            day_count[day_no]++;
                        }
                    }
                }
            }
        }
    }
    int m;
    for( m=0;m<7-1;m++){
        cout<<day_count[day_name[m]]<<" ";
    }
    cout<<day_count[day_name[m]]<<endl;

    return 0;
}

