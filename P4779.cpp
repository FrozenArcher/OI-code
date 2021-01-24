// 模板：dijkstra
#include <bits/stdc++.h>
#define MAXN 100010
#define MAXM 500010
using std::priority_queue;
using std::vector;

struct node
{
    int pos, dis;
    bool operator<(const node &n) const
    {
        return n.dis < dis;
    }
};

struct edge
{
    int to, cost;
};

vector<edge> eg[MAXN];
priority_queue<node> q;
int n, m, s, dis[MAXN];
bool vis[MAXN];

void dijkstra()
{
    dis[s] = 0;
    q.push((node){s, 0});

    while (!q.empty())
    {
        node tmp = q.top();
        q.pop();

        int id = tmp.pos, dst = tmp.dis;
        if (vis[id])
            continue;
        vis[id] = true;

        for (int i = 0; i < eg[id].size(); i++)
        {
            int to = eg[id][i].to, cost = eg[id][i].cost;
            if (dis[to] > dis[id] + cost)
                dis[to] = dis[id] + cost;
            if (!vis[to])
                q.push((node){to, dis[id] + cost});
        }
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i <= n; i++)
        dis[i] = 0x7fffffff;
    for (int i = 1; i <= m; i++)
    {
        int __U, __V, __D;
        scanf("%d%d%d", &__U, &__V, &__D);
        eg[__U].push_back((edge){__V, __D});
    }
    dijkstra();
    for (int i = 1; i <= n; i++)
        printf("%d ", dis[i]);
}
