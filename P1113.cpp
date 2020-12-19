#include <iostream>
#include <cstdio>
#include <vector>
#define MAXN 10010
using namespace std;

int n, ans;
int len[MAXN], vis[MAXN];
vector<int> linker[MAXN];

int dfs(int x)
{
    if (!vis[x]) //x is not visited, then calculate shortest time
    {
        //int j =linker[x].size();
        for (int i = 0; i < linker[x].size(); i++)   //go through all the points
            vis[x] = max(vis[x], dfs(linker[x][i])); // find the longest
        vis[x] += len[x];                            //add iteslf's time
    }
    return vis[x];
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> len[i];
        while (cin >> y)
            if (!y)
                break;
            else
                linker[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
        ans = max(ans, dfs(i));

    cout << ans;
    return 0;
}