#include <bits/stdc++.h>
#define MAXN 105
using std::priority_queue;

struct node
{
    int x, y, dis, c;
    bool operator<(const node &n) const
    {
        return n.dis < dis;
    }
};

int map[MAXN][MAXN], dis[MAXN][MAXN], m, n;
bool vis[MAXN][MAXN], flag = false;
priority_queue<node> q;

int gox[12] = {0, 0, 1, -1, 0, 0, 2, -2, 1, 1, -1, -1};
int goy[12] = {1, -1, 0, 0, 2, -2, 0, 0, 1, -1, 1, -1};
int mag[12] = {0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2};

int bfs()
{
    q.push((node){1, 1, 0, map[1][1]});
    dis[1][1] = 0;

    while (!q.empty())
    {
        int _x = q.top().x, _y = q.top().y, _dis = q.top().dis, cost = 0;
        q.pop();
        if (vis[_x][_y] || !map[_x][_y])
        {
            continue;
        }
        if (_x == m && _y == m)
        {
            flag = true;
            break;
        }
        vis[_x][_y] = true;
        for (int i = 0; i < 12; i++)
        {
            int x = _x + gox[i], y = _y + goy[i];
            if (x <= 0 || y <= 0 || x > m || y > m || !map[x][y])
            {
                continue;
            }
            cost += mag[i];
            if (map[x][y] != map[_x][_y])
            {
                cost++;
            }
            if (dis[_x][_y] + cost < dis[x][y])
            {
                dis[x][y] = dis[_x][_y] + cost;
            }
            if (!vis[x][y] && map[x][y])
            {
                q.push((node){x, y, dis[x][y], map[x][y]});
            }
        }
    }
    if (flag)
    {
        return dis[1][1];
    }
    else
    {
        return -1;
    }
}

int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++)
    {
        int __X, __Y, __C;
        scanf("%d%d%d", &__X, &__Y, &__C);
        map[__X][__Y] = __C + 1;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dis[i][j] = 0x3f3f3f3f;
        }
    }
    printf("%d", bfs());
    return 0;
}
