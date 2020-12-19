#include <iostream>
#include <cstring>
#define  MAX_N 25
using namespace std;

int   n,m;
bool  vis[MAX_N];
int   linker[MAX_N][MAX_N];
int   ans,__ans;

int max(int x, int y)
{
    if(x>y) return x;
    else return y;
}

void dfs(int x, int DIS_NOW)
{
    __ans=max(__ans, DIS_NOW);
    for(int i=1;i<=n;i++)
    {
        if(linker[x][i] > 0 && vis[i] == 0)
        {
            vis[i]=1;
            dfs(i, DIS_NOW + linker[x][i]);
            vis[i]=0;
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int from,to,cost;
        cin>>from>>to>>cost;
        linker[from][to]=linker[to][from]=cost;
    }
    for(int i=1;i<=n;i++)
    {
        vis[i]=1;
        dfs(i, 0);
        ans=max(ans,__ans);
        __ans=0;
        memset(vis, 0, sizeof(vis));
    }
    cout<<ans;
    return 0;
}