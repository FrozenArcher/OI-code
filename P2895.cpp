#include <iostream>
#include <cstdio>
#include <queue>
#define MAXN 310
#define position_i(_x, _y) (_x)+xpos[i]][(_y)+ypos[i]
#define X p.x
#define Y p.y
#define T p.t
using namespace std;

struct point
{
    int x, y, t;
};
queue<point> q;

int ypos[4] = {-1, -1, 1, 1};
int xpos[4] = {-1, 1, -1, 1};

int _time[MAXN][MAXN], safe[MAXN][MAXN];
bool vis[MAXN][MAXN];

int m, mint;

point makePoint(int __X, int __Y, int __T)
{
    point p;
    p.t = __T;
    p.x = __X;
    p.y = __Y;
    return p;
}

int main()
{
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int __X, __Y, __T;
        cin >> __X >> __Y >> __T;
        _time[__X][__Y] = __T;
        safe[__X][__Y] = false;
        for (int i = 0; i < 4; i++)
        {
            if (__X + xpos[i] >= 0 && __Y + ypos[i] >= 0)
            {
                _time[position_i(__X, __Y)] = __T;
                safe[position_i(__X, __Y)] = false; //try to remove this
            }
        }
    }
    for (int i = 0; i <= 301; i++)
        vis[301][i] = vis[i][301] = true;

    mint = 1e9;
    q.push(makePoint(0, 0, 0));

    while (!q.empty())
    {
        point p = q.front();
        q.pop();

        if (vis[X][Y] || X < 0 || Y < 0 || T > mint || T >= _time[X][Y])
            continue;

        if (safe[X][Y])
        {
            mint = min(mint, T);
            continue;
        }

        for (int i = 0; i < 4; i++)
        {
            if (X + xpos[i] >= 0 && Y + ypos[i] >= 0)
                if (T < _time[position_i(X, Y)] && !vis[position_i(X, Y)])
                    q.push(makePoint(X + xpos[i], Y + ypos[i], T + 1));
        }
    }

    cout << ((mint >= 1e9) ? -1 : mint) << endl;
}
