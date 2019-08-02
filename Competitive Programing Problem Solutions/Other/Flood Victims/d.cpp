#include<bits/stdc++.h>
using namespace std;
int ans=0;
bool compareSeq(char S[], int x, int y, int n){
    for (int i=0;i<n;i++){
        if (S[x] < S[y])
            return false;
        else if (S[x] > S[y])
            return true;
        x = (x+1)%n;
        y = (y+1)%n;
    }
    return true;
}
int smallestSequence(char S[], int n){
    int index = 0;
    for (int i=1; i<n; i++)
        if (compareSeq(S, index, i, n))
            index = i;
    return index;
}
void printSmallestSequence(char S[], int n){
    int starting_index = smallestSequence(S, n);
    for (int i=0;i<15;i++)
        ans+=S[(starting_index+i)%n]-'a'+1;
//    printf("\n");
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
//    string s;
//    cin>>s;
//    int n=s.length();
    char S[2001];
    scanf("%s",&S);
    getchar();
    int n = strlen(S);
    printSmallestSequence(S, n);
    }
    printf("%d\n",ans);
    return 0;
}
