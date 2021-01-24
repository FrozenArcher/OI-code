#include <cstdio>
#include <cstring>
#define MAXN 11

int n;
int map[1 << MAXN][1 << MAXN], tmp[1 << MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= (1 << n); i++)
    {
        for (int j = 1; j <= (1 << n); j++)
        {
            map[i][j] = 1;
        }
    }
    
    for (int i = 1; i <= 1 << n; i++)
    {
        memset(tmp, 0, sizeof(tmp));
        for (int j = (1 << n); j > (1 << n) - i; j--)
        {
            tmp[j] = map[i][j];
        }
    }

    for (int i = 1; i <= (1 << n); i++)
    {
        for (int j = 1; j <= (1 << n); j++)
        {
            printf("%d ", map[i][j]);
            if (j == (1 << n))
            {
                puts("");
            }
        }
    }
    return 0;
}
