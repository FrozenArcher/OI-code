#include <cstdio>
#include <cstring>
#define MAXN 100000050
#define rg register

int prime[MAXN], cnt = 0;
bool isPrime[MAXN];

void init(int n)
{
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[1] = 0;
    for (rg int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            prime[++cnt] = i;
        }
        for (rg int j = 1; j <= cnt && i * prime[j] <= n; j++)
        {
            isPrime[i * prime[j]] = 0;
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }
}

signed main()
{
    int n, q, k;
    scanf("%d%d", &n, &q);
    init(n);
    for (rg int i = 1; i <= q; i++)
    {
        scanf("%d", &k);
        printf("%d\n", prime[k]);
    }
    return 0;
}
