/// C++ code to demonstrate operations of Binary Index Tree
#include<bits/stdc++.h>
using namespace std;

int getSum(int BITree[], int index){
    int sum = 0;
    index = index+1;
    while (index>0){
        sum += BITree[index];/// Move index to parent node in getSum View
        index -= index & (-index);
    }
    return sum;
}
int range_query(int BITree[],int u,int v){
    return getSum(BITree,v)-getSum(BITree,u-1);
}
void updateBIT(int BITree[], int n, int index, int val){
    index = index+1;
    while (index <= n){
       BITree[index] += val;/// Update index to that of parent in update View
       index += index & (-index);
    }
}
/// Constructs and returns a Binary Indexed Tree for given array of size n.
int *constructBITree(int arr[], int n){
    int *BITree = new int[n+1];
    for (int i=1; i<=n; i++)
        BITree[i] = 0;/// Create and initialize BITree[] as 0
    for (int i=0; i<n; i++)
        updateBIT(BITree, n, i, arr[i]);/// Store the actual values in BITree[] using update()

    // Uncomment below lines to see contents of BITree[]
    //for (int i=1; i<=n; i++)
    //      cout << BITree[i] << " ";

    return BITree;
}
int main(){
    int freq[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(freq)/sizeof(freq[0]);
    int *BITree = constructBITree(freq, n);
    cout << "Sum of elements in arr[0..5] is "<< getSum(BITree, 5);
    updateBIT(BITree, n, 3, 6);
    cout << "\nSum of elements in arr[0..5] after update is "<< getSum(BITree, 5);
    cout << "\nSum of elements in arr[i....j] is "<< range_query(BITree, 2,6);
    return 0;
}
