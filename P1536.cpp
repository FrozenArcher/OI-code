#include<iostream>
#include<cstdio>
#define MAXN 10005
using namespace std;

int fa[MAXN];

int find(int x)
{
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

void join(int x, int y)
{
    fa[find(x)] = find(y);
}

int main()
{
    int n;
    while(cin >> n)
    {
        if(!n) break;
        for(int i=1; i<=n; i++)
            fa[i] = i;
        int m;
        cin>>m;
        for(int i=1; i<=m; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            join(x, y);
        }
        int ans = 0;
        for(int i=1; i<=n; i++)
            if(fa[i] == i) ans++;
        
        printf("%d\n", ans-1);
    }

    return 0;
}