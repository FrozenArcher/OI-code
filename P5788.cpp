#include <cstdio>
#define MAXN 3000050
#define pop() s[cnt--]
#define push(x) s[++cnt] = (x)
#define top s[cnt]
#define rg register

int a[MAXN], s[MAXN], f[MAXN], cnt = 0, n;

int main()
{
    // freopen("P5788in.txt", "r", stdin);
    // freopen("P5788out.txt", "w", stdout);
    scanf("%d", &n);
    for (rg int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (rg int i = 1; i <= n; i++)
    {
        while (cnt && a[top] < a[i])
        {
            f[pop()] = i;
        }
        push(i);
    }
    for (rg int i = 1; i <= n; i++)
    {
        printf("%d ", f[i]);
    }
    return 0;
}
