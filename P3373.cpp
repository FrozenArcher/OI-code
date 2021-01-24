// 模板 线段树2
#include <cstdio>
#define MAXN 100010
#define ls rt << 1
#define rs rt << 1 | 1

struct node
{
    long long val, mul, add;
} st[MAXN << 2];

int n, m, p, opr, x, y, ___ = 0;
long long a[MAXN], k;

void build(int rt, int l, int r)
{
    st[rt].mul = 1;
    st[rt].add = 0;
    if (l == r)
    {
        st[rt].val = a[l] % p;
        return;
    }
    int m = (l + r) >> 1;
    build(ls, l, m);
    build(rs, m + 1, r);
    st[rt].val = (st[ls].val + st[rt].val) % p;
}

void push_down(int rt, int l, int r)
{
    int m = (l + r) >> 1;
    st[ls].val = (st[ls].val * st[rt].mul + st[rt].add * (m - l + 1)) % p;
    st[rs].val = (st[rs].val * st[rt].mul + st[rt].add * (r - m)) % p;
    st[ls].mul = (st[ls].mul * st[rt].mul) % p;
    st[rs].mul = (st[rs].mul * st[rt].mul) % p;
    st[ls].add = (st[ls].add * st[rt].mul + st[ls].add) % p;
    st[rs].add = (st[rs].add * st[rt].mul + st[rt].add) % p;
    st[rt].mul = 1;
    st[rt].add = 0;
}

void upd_mul(int rt, int cl, int cr, int l, int r, int k)
{
    if (r < cl || cr < l)
    {
        return;
    }
    if (l <= cl && cr <= r)
    {
        st[rt].mul = (st[rt].mul * k) % p;
        st[rt].val = (st[rt].val * k) % p;
        return;
    }
    push_down(rt, cl, cr);
    int m = (l + r) >> 1;
    upd_mul(ls, cl, m, l, r, k);
    upd_mul(rs, m + 1, cr, l, r, k);
    st[rt].val = (st[ls].val + st[rs].val) % p;
}
