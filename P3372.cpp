// SegmentTree 模板1
#include <cstdio>
#define MAXN 1000010
#define ls p << 1
#define rs p << 1 | 1

typedef long long ll;
ll val[MAXN], tag[MAXN], a[MAXN];
ll opr, x, y, k, n, m;

inline void update(ll p)
{
    val[p] = val[ls] + val[rs];
}

void build(ll p, ll l, ll r)
{
    tag[p] = 0;
    if (l == r)
    {
        val[p] = a[l];
        return;
    }
    ll m = (l + r) >> 1;
    build(ls, l, m);
    build(rs, m + 1, r);
    update(p);
}

void push_down(ll p, ll l, ll r)
{
    ll m = (l + r) >> 1;
    tag[ls] += tag[p];
    tag[rs] += tag[p];
    val[ls] += tag[p] * (m - l + 1);    // !!!
    val[rs] += tag[p] * (r - m);        // !!!
    tag[p] = 0;
}

void add(ll p, ll l, ll r, ll al, ll ar, ll ak)
{
    if (ar < l || r < al)
    {
        return;
    }
    if (al <= l && r <= ar)
    {
        val[p] += ak * (r - l + 1);         // !!!
        tag[p] += ak;                   
        return;
    }
    push_down(p, l, r);
    ll m = (l + r) >> 1;
    add(ls, l, m, al, ar, ak);
    add(rs, m + 1, r, al, ar, ak);
    update(p);
}

ll query(ll p, ll l, ll r, ll al, ll ar)
{
    if (ar < l || r < al)
    {
        return 0;
    }
    if (al <= l && r <= ar)
    {
        return val[p];
    }
    push_down(p, l, r);
    ll m = (l + r) >> 1;
    return query(ls, l, m, al, ar) + query(rs, m + 1, r, al, ar);
}

int main()
{
    scanf("%lld%lld", &n, &m);
    for (ll i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    build(1, 1, n);
    for (ll i = 1; i <= m; i++)
    {
        scanf("%lld", &opr);
        if (opr == 1)
        {
            scanf("%lld%lld%lld", &x, &y, &k);
            add(1, 1, n, x, y, k);
        }
        else
        {
            scanf("%lld%lld", &x, &y);
            printf("%lld\n", query(1, 1, n, x, y));
        }
    }
    return 0;
}
