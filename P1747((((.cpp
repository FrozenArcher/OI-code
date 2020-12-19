#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
#define ABCDE memset(vis, false, sizeof(vis));memset(dis, false, sizeof(dis)); 
using namespace std;
struct Pos
{
    int x, y;
};
queue<Pos> q; //定义队列
const int n = 20;
const int dx[] = {2, 2, 2, 2, 1, 1, -1, -1, -2, -2, -2, -2};
const int dy[] = {-2, -1, 1, 2, -2, 2, -2, 2, -2, -1, 1, 2}; //定义12个方向
int x, y, tx, ty, a_x, a_y, b_x, b_y, dis[21][21], ans_a, ans_b;
bool vis[21][21];
int bfs(int sx, int sy)
{
    ABCDE
    while (!q.empty())
        q.pop();
    q.push((Pos){sx, sy}); //加入队列
    vis[sx][sy] = true;
    while (!q.empty())
    {
        x = q.front().x;
        y = q.front().y;
        q.pop();
        if (x + y == 2)
            return dis[1][1];
        for (int i = 0; i < 12; i++)
        {
            tx = x + dx[i];
            ty = y + dy[i];
            if (tx <= 0 || tx > n || ty <= 0 || ty > n)
                continue;
            if (vis[tx][ty] == true)
                continue;
            dis[tx][ty] = dis[x][y] + 1;
            vis[tx][ty] = true;
            q.push((Pos){tx, ty}); //弹出
        }
    }
}
int main()
{
    scanf("%d%d", &a_x, &a_y);
    scanf("%d%d", &b_x, &b_y);
    ans_a = bfs(a_x, a_y);
    ans_b = bfs(b_x, b_y);
    cout << ans_a << endl;
    cout << ans_b << endl;
    return 0;
}