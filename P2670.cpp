#include <cstdio>
#define MAXN 105
char map[MAXN][MAXN];
int gox[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int goy[8] = {1, -1, 0, 0, -1, 1, 1, -1};
int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%s", map[i] + 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (map[i][j] == '*')
                continue;
            int cnt = 0;
            for (int go = 0; go < 8; go++)
                if (map[i + gox[go]][j + goy[go]] == '*')
                    cnt++;
            map[i][j] = '0' + cnt;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            printf("%c", map[i][j]);
            if (j == m)
                puts("");
        }
    return 0;
}
