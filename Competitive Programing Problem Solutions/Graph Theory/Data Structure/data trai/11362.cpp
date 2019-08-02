#include<bits/stdc++.h>
using namespace std;
const int mx = 11;
struct Node {
    bool end_mark;
    Node *next[mx];

    Node() {
        for(int i = 0; i < 10; i++) {
            next[i] = nullptr;
            end_mark = false;
        }
    }
};
Node *root;

bool Insert(char *s)
{
    Node *curr = root;
    int i, id;
    for(i = 0; i < s[i]; i++)
    {
        int a=s[i];
        cout<<i<<" "<<a<<endl;
        if(curr->end_mark == true) {
            return true;
        }
        id = s[i] - '0';
        if(curr->next[id] == nullptr) {
            curr->next[id] = new Node();
        }
        curr = curr->next[id];
    }
    curr->end_mark = true;
    cout<<"go"<<endl;
    //i = i - 1;
    // if last node's all next is not empty
    // then this is an prefix of some number.
    for(int i = 0; i <= 9; i++) {
        if(curr->next[i] != nullptr) {
            return true;
        }
    }
    return false;
}

int main()
{
    //freopen("input.txt", "r+", stdin);

    int tc, number;
    char s[20];

    scanf("%d", &tc);
    int t = 1;
    while(tc--)
    {
        bool flag = false;
        root = new Node();

        scanf("%d", &number);
        cin.ignore();

        for(int i = 0; i < number; i++)
        {
            scanf("%s", s);
            if(flag == false) {
                flag = Insert(s);
            }
        }
        flag == false ? printf("YES\n") : printf("NO\n");
    }
    return 0;
}
