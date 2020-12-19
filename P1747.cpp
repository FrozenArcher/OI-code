#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct node
{
    int x, y;
};

int vis[40][40];
int gox[12] = {1, 1, -1, -1, 2, -1, 2, -2, 2, 2, -2, -2};
int goy[12] = {2, -2, 2, -2, 1, 1, -1, -1, -2, 2, -2, 2};
queue<node> q;
int x1, _y1, x2, y2, ans;

void BFS(int x, int y)
{
    q.push((node){x, y});
    vis[x][y] = 0;
    while (!q.empty())
    {
        node ___N = q.front();
        q.pop();
        int ux = ___N.x, uy = ___N.y;
        if (ux != 1 && uy != 1)
            for (int i = 0; i < 12; i++)
            {
                int nx = ux + gox[i], ny = uy + goy[i];
                if (nx > 0 && ny > 0 && nx < 30 && ny < 30 && vis[nx][ny] == -1)
                {
                    q.push((node){nx, ny});
                    vis[nx][ny] = vis[ux][uy] + 1;
                }
            }
    }

    cout << vis[1][1]<< endl;
    return;
}

int main()
{
    
    cin >> x1 >> _y1;
    cin >> x2 >> y2;
    memset(vis, -1, sizeof(vis));
    BFS(x1, _y1);
    memset(vis, -1, sizeof(vis));
    while(!q.empty()) q.pop();
    BFS(x2, y2);
    return 0;
}