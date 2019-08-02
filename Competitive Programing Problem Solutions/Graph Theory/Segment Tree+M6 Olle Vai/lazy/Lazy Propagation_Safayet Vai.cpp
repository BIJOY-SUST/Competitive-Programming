#include<bits/stdc++.h>
using namespace std;
#define mx 100001
int arr[mx];
struct info {
    int prop, sum;
} tree[mx * 3];

void init(int node, int b, int e){
    if (b == e) {
        tree[node].sum = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node].sum = tree[Left].sum + tree[Right].sum;
}
void update(int node, int b, int e, int i, int j, int x){
    if (i > e || j < b)
        return;
    if (b >= i && e <= j)
    {
        tree[node].sum += ((e - b + 1) * x);
        tree[node].prop += x;
        return;
    }
    int Left = node * 2;
    int Right = (node * 2) + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    tree[node].sum = tree[Left].sum + tree[Right].sum + (e - b + 1) * tree[node].prop;
}
int query(int node, int b, int e, int i, int j, int carry = 0)
{
    if (i > e || j < b)
        return 0;

    if (b >= i and e <= j)
        //cout<<carry<<"\n";
        return (tree[node].sum + carry * (e - b + 1));

    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (b + e) >> 1;

    int p1 = query(Left, b, mid, i, j, carry + tree[node].prop);
    int p2 = query(Right, mid + 1, e, i, j, carry + tree[node].prop);

    return p1 + p2;
}

int main(){
    int n,q,a,b,c;
    cin >> n>>q;
    for(int i=1;i<=n;i++)
        arr[i]=0;
    init(1, 1, n);
    while (q--) {
        scanf("%d%d%d",&a,&b,&c);
        b+=1, c+=1;
        if (a == 0) {
            update(1,1,n,b,c,1);
        } else {
            printf("%d\n", query(1,1,n,b,c));
        }
    }
    return 0;
}
