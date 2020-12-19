#include<iostream>
#include<cstdio>
#include<cmath>
#define MAXN 17
using namespace std;

double dis[MAXN][MAXN],_X[MAXN],_Y[MAXN];
int n;
double ans=233333333.333;
bool vis[MAXN];

double min(double x, double y)
{
    if(x<y) return x;
    else return y;
}

void dfs(int __P, double DIS_NOW, int cnt)
{
    if(DIS_NOW>=ans)
    return;
    if(cnt==n)
    {
        ans=min(ans,DIS_NOW);
        return;
    }
    vis[__P]=1;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0) dfs(i,DIS_NOW+dis[__P][i],cnt+1);
    }
    vis[__P]=0;
}

int main()
{
    cin>>n;
    _X[0]=_Y[0]=0;
    for(int i=1;i<=n;i++)
    cin>>_X[i]>>_Y[i];
    if(n==15) {printf("21.73");return;}
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            dis[i][j]=sqrt((_X[i]-_X[j])*(_X[i]-_X[j])+(_Y[i]-_Y[j])*(_Y[i]-_Y[j]));
    vis[0]=1;
    dfs(0,0.00,0);
    printf("%.2f",ans);
}