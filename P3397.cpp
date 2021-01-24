#include <cstdio>
#define MAXN 1050
int n, m;
int ans[MAXN][MAXN];
int min(int a, int b)
{
    return a < b ? a : b;
}
int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        for (int i = min(x1, x2); i <= max(x1, x2); i++)
            for (int j = min(y1, y2); j <= max(y1, y2); j++)
                ans[i][j]++;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            printf("%d", ans[i][j]);
            if (j % n == 0)
                printf("\n");
            else
                printf(" ");
        }
    return 0;
}