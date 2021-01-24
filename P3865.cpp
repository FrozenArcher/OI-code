#include <bits/stdc++.h>
#define MAXN 100010
#define rg register
using std::max;

int MAX[MAXN][21];

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}

int query(int l, int r)
{
    int k = log2(r - l + 1);
    return max(MAX[l][k], MAX[r - (1 << k) + 1][k]);
}

signed main()
{
    int n = read(), m = read();
    for (rg int i = 1; i <= n; i++)
    {
        MAX[i][0] = read();
    }
    for (rg int j = 1; j <= 21; j++)
    {
        for (rg int i = 1; i + (1 << (j - 1)) <= n; i++)
        {
            MAX[i][j] = max(MAX[i][j - 1], MAX[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (rg int i = 1; i <= m; i++)
    {
        int l = read(), r = read();
        printf("%d\n", query(l, r));
    }
    return 0;
}
