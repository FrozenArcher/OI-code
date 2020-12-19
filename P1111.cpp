#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 1050
#define MAXM 100050
using namespace std;

struct road
{
    int va, vb, tm;
} rd[MAXM];

int n, m, ans;
int fa[MAXN];

int find(int x)
{
    if (fa[x] == x)
        return x;
    else
        return fa[x] = find(fa[x]);
}

void join(int a, int b)
{
    int anc1 = find(a), anc2 = find(b);
    if (anc1 != anc2)
        fa[anc1] = anc2;
}

bool cmp(road &a, road &b)
{
    return a.tm < b.tm;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &rd[i].va, &rd[i].vb, &rd[i].tm);
    }
    sort(rd + 1, rd + m + 1, cmp);
    for (int i = 1; i <= m; i++)
    {
        join(rd[i].va, rd[i].vb);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << fa[i] <<' ';
    }
    return 0;
}
