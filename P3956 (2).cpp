#include <bits/stdc++.h>
#define maxn 100005
#define maxm 2000005
using std::min;

struct Edge
{
    int f, t, w, nxt;
} edge[maxm];

int head[maxn], etot = 1;

void add_edge(int f, int t, int w)
{
    edge[++etot] = (Edge){f, t, w, head[f]};
    head[f] = etot;
}

int tr[maxn << 2], dis1[maxn << 2], bt;
int n, m, S, T;

void build()
{
    for (bt = 1; bt <= n + 1; bt <<= 1)
        ;
    for (int i = 1; i <= n; i++)
        tr[i + bt] = i;
    memset(dis1, 0x3f, sizeof(dis1));
}

void modify(int x, int val)
{
    dis1[x] = val;
    x += bt;
    for (x >>= 1; x; x >>= 1)
    {
        if (dis1[tr[x << 1]] < dis1[tr[(x << 1) | 1]])
            tr[x] = tr[x << 1];
        else
            tr[x] = tr[(x << 1) | 1];
    }
}

int dis[maxn];
void dijkstra()
{
    memset(dis, 0x3f, sizeof(dis));
    build();
    dis[S] = 0;
    modify(S, 0);
    int x, y, w;
    for (int j = 1; j <= n; j++)
    {
        x = tr[1];
        modify(x, 0x3f3f3f3f);
        for (int i = head[x]; i; i = edge[i].nxt)
        {
            y = edge[i].t;
            w = edge[i].w;
            if (dis[y] > dis[x] + w)
            {
                dis[y] = dis[x] + w;
                modify(y, dis[y]);
            }
        }
    }
}

int dx[] = {0, 1, 0, -1, 1, 1, -1, -1, 0, 2, 0, -2};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1, 2, 0, -2, 0};
int dw[] = {0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2};
int a[105][105], cnt[105][105];

struct node
{
    int x, y, c;
} b[maxn];

void preprocess()
{
    int x, y, c, xx, yy, ww;
    for (int i = 1; i <= n; i++)
    {
        x = b[i].x;
        y = b[i].y;
        c = b[i].c;
        for (int j = 0; j < 12; j++)
        {
            xx = x + dx[j];
            yy = y + dy[j];
            ww = dw[j];
            if (a[xx][yy])
            {
                if (a[xx][yy] != c)
                    ww++;
                add_edge(i, cnt[xx][yy], ww);
            }
        }
    }
    S = cnt[1][1];
}
int main()
{
    int mm, x, y, c;
    scanf("%d%d", &mm, &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &x, &y, &c);
        a[x][y] = ++c;
        cnt[x][y] = i;
        b[i] = (node){x, y, c};
    }
    preprocess();
    dijkstra();
    if (!a[mm][mm])
    {
        int ans = min(dis[cnt[mm][mm - 1]], dis[cnt[mm - 1][mm]]) + 2;
        if (ans >= 0x3f3f3f3f)
            printf("-1");
        else
            printf("%d", ans);
    }
    else
    {
        if (dis[cnt[mm][mm]] == 0x3f3f3f3f)
            printf("-1");
        else
            printf("%d", dis[cnt[mm][mm]]);
    }
    return 0;
}