#include<bits/stdc++.h>
using namespace std;
void preorder(int n){
    if(n==1||n==2){
        cout<<" "<<n;
        return;
    }
    cout<<" "<<n;
    preorder(n-2);
    preorder(n-1);
}
void inorder(int n){
    if(n==1||n==2){
        cout<<" "<<n;
        return;
    }

    inorder(n-2);
    cout<<" "<<n;
    inorder(n-1);
}
void postorder(int n){
    if(n==1||n==2){
        cout<<" "<<n;
        return;
    }

    postorder(n-2);
    postorder(n-1);
    cout<<" "<<n;
}
int main(){
    int n;
    cin>>n;
    cout<<"Preorder:";
    preorder(n);
    cout<<endl;
    cout<<"Inorder:";
    inorder(n);
    cout<<endl;
    cout<<"Postorder:";
    postorder(n);


    return 0;
}
