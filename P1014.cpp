#include <iostream>
#define MAXN 10000050
using namespace std;

int up[MAXN], down[MAXN];
int n;

int main()
{
    cin >> n;
    int x = 1;
    for (int i = 1; i <= n;)
    {
        for (int j = 1; j <= x; j++)
        {
            up[i] = j;
            i++;
        }
        for (int j = x - 1; j >= 1; j--)
        {
            up[i] = j;
            i++;
        }
        x += 2;
    }
    x = 2;
    for (int i = 1; i <= n;)
    {
        for (int j = 1; j <= x; j++)
        {
            down[i] = j;
            i++;
        }
        for (int j = x - 1; j >= 1; j--)
        {
            down[i] = j;
            i++;
        }
        x += 2;
    }
    // for (int i = 1; i <= n; i++)
        // cout << up[i] << '/' << down[i] << ' ';
    cout << up[n] << '/' << down[n];
}
