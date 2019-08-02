#include<bits/stdc++.h>
using namespace std;
void heapify(int a[],int heapsize,int root)
{
    int left,right,largest=root,temp;
    left=2*root;
    right=2*root+1;
    if(left<=heapsize && a[left]>a[root]) largest=left;
    if(right<=heapsize && a[right]>a[largest]) largest=right;
    if(largest != root)
    {
        temp=a[largest];
        a[largest]=a[root];
        a[root]=temp;

        heapify(a,heapsize,largest);
    }
}
void buildheap(int a[],int n)
{
    int i;
    for(i=n/2;i>=1;i--) heapify(a,n,i);
}
void heapsort(int a[],int n)
{
    buildheap(a,n);
    int heapsize=n,temp,i;
    for(i=n;i>=1;i--)
    {
        temp=a[1];
        a[1]=a[i];
        a[i]=temp;

        heapsize--;
        heapify(a,heapsize,1);
    }
}
int main()
{
    int numbers[100],i,n;
    cin>>n;
    for(i=1;i<=n;i++) cin>>numbers[i];
    heapsort(numbers,n);
    cout<<"sorted numbers: "<<endl;
    for(i=1;i<=n;i++) cout<<numbers[i]<<" ";
    return 0;
}
