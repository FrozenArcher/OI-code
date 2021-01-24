#include <cstdio>
unsigned long long map[22][22];
int x, y, hx, hy;
inline bool underControl(int x, int y)
{
    return ((x == hx) && (y == hy)) ||         // horse point
           ((x == hx - 1) && (y == hy - 2)) || // point1
           ((x == hx - 1) && (y == hy + 2)) || // point2
           ((x == hx + 1) && (y == hy - 2)) || // point3
           ((x == hx + 1) && (y == hy + 2)) || // point4

           ((x == hx - 2) && (y == hy - 1)) || // point1
           ((x == hx - 2) && (y == hy + 1)) || // point2
           ((x == hx + 2) && (y == hy - 1)) || // point3
           ((x == hx + 2) && (y == hy + 1));   // point4
}
int main()
{
    scanf("%d%d%d%d", &x, &y, &hx, &hy);
    map[0][0] = 1;
    for (int i = 0; i <= x; i++)
        for (int j = 0; j <= y; j++)
            if (!underControl(i, j))
            {
                if (j && (!underControl(i, j - 1)))
                    map[i][j] += map[i][j - 1];
                if (i && (!underControl(i - 1, j)))
                    map[i][j] += map[i - 1][j];
            }
    printf("%lld", map[x][y]);
}