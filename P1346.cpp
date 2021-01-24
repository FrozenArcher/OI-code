/*
#include <bits/stdc++.h>
#define MAXN 105
using std::priority_queue;
using std::vector;

struct node
{
    int pos, dis;
    bool operator<(const node &n) const
    {
        return n.pos < pos;
    }
};

struct edge
{
    int to, cost;
};

int n, start, end, dis[MAXN];
bool vis[MAXN];
priority_queue<node> q;
vector<edge> eg[MAXN];

int main()
{
    scanf("%d%d%d", &n, &start, &end);
    for (int i = 0; i <= n; i++)
        dis[i] = 0x7fffffff;
    for (int i = 1; i <= n; i++)
    {
        eg[i].push_back((edge){i, 0});
        int cnt;
        scanf("%d", &cnt);
        for (int j = 1; j <= cnt; j++)
        {
            int _to, _cost;
            scanf("%d", &_to);
            _cost = (j != 1) ? 1 : 0;
            eg[i].push_back((edge){_to, _cost});
        }
    }
    for (int i = 0; i < eg[i].size(); i++)
        dis[eg[start][i].to] = eg[start][i].cost;
    dis[start] = 0;
    q.push((node){start, 0});

    while (!q.empty())
    {
        node tmp = q.top();
        q.pop();
        int id = tmp.pos;
        if (vis[id])
            continue;
        if (id == end)
        {
            printf("%d", dis[end]);
            return 0;
        }
        for (int i = 0; i < eg[id].size(); i++)
        {
            int to = eg[id][i].to, cost = eg[id][i].cost;
            if (dis[to] > dis[id] + cost)
                dis[to] = dis[id] + cost;
            if (!vis[to])
                q.push((node){to, dis[to]});
        }
    }

    puts("-1");
    return 0;
}
*/
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n, s, e, m, x, f[1001][1001], dis[100001];
bool vis[100001];
void __init()
{
    memset(f, INF, sizeof(f));
    memset(dis, INF, sizeof(dis));
}
void __read()
{
    scanf("%d %d %d", &n, &s, &e);
    for (int i = 1; i <= n; i++)
        f[i][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &m);
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &x);
            f[i][x] = (j == 1) ? 0 : 1;
        }
    }
    for (int i = 1; i <= n; i++)
        dis[i] = f[s][i];
}
void __DFS()
{
    dis[s] = 0;
    for (int i = 1; i <= n; i++)
    {
        int minn = INF;
        int k = 0;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && dis[j] < minn)
            {
                minn = dis[j];
                k = j;
            }
        }
        if (k == 0)
            break;
        vis[k] = true;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && dis[j] > dis[k] + f[k][j]) 
                dis[j] = dis[k] + f[k][j]; 
        }
    }
}
void __write()
{
    if (dis[e] == INF)
        puts("-1");
    else
        printf("%d", dis[e]);
}
int main()
{
    __init();
    __read();
    __DFS();
    __write();
    return 0;
}
