#include<bits/stdc++.h>
#define mx 10001
using namespace std;
float arr[mx];
void bucket_sort(int n){
    map<float,vector<float> >elements;
    for(int i=0;i<n;i++){
        int p=n*arr[i];
        elements[p].push_back(arr[i]);
    }
    for(int i=0;i<n;i++){
        sort(elements[i].begin(),elements[i].end());
    }
    int index=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<elements[i].size();j++){
            arr[index++]=elements[i][j];
        }
    }

}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%f",&arr[i]);
    }
    bucket_sort(n);
    for(int i=0;i<n;i++){
        printf("%0.4f ",arr[i]);
    }
    printf("\n");
    return 0;
}


