#include <bits/stdc++.h>
#define MAXN 2550
#define MAXM 6250
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

int n, m, s, t;
int dis[MAXN], vis[MAXN];
vector<edge> eg[MAXN];
priority_queue<node> q;

int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 1; i <= m; i++)
    {
        int _U, _V, _W;
        scanf("%d%d%d", &_U, &_V, &_W);
        eg[_U].push_back((edge){_V, _W});
        eg[_V].push_back((edge){_U, _W});
    }
    for (int i = 0; i <= n; i++)
    {
        dis[i] = 0x7fffffff;
    }

    dis[s] = 0;
    q.push((node){s, 0});

    while (!q.empty())
    {
        node tmp = q.top();
        q.pop();
        int id = tmp.pos;
        if (id == t)
            break;
        if (vis[id])
            continue;
        vis[id] = true;

        for (int i = 0; i < eg[id].size(); i++)
        {
            int to = eg[id][i].to, cost = eg[id][i].cost;
            if (dis[id] + cost < dis[to])
                dis[to] = dis[id] + cost;
            if (!vis[to])
                q.push((node){to, dis[to]});
        }
    }
    
    printf("%d", dis[t]);
    return 0;
}
