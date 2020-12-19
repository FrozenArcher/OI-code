#include <iostream>
using namespace std;
struct node
{
    char left, right, p;
}tree[1000];
void visit(char x)
{
    cout<<x;
    if (tree[x].left != '*')
        visit(tree[x].left);
    if (tree[x].right != '*')
        visit(tree[x].right);
}
int main()
{
    int n;
    cin>>n;
    char root;
    for(int i=1; i<=n; i++)
    {
        char c, ls, rs;
        cin>>c>>ls>>rs;
        if (i==1)
            root = c;
        tree[c].left = ls;
        tree[c].right = rs;
        tree[ls].p = tree[rs].p = c;
    }
    visit(root);
    return 0;
}