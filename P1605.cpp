#include<iostream>
#include<cstdio>
#define MAXN 7
using namespace std;

int bar[MAXN][MAXN];         //map
int vis[MAXN][MAXN];         //visit
int n,m;                     //n*m map
int t;                       //total barrier
int sx,sy,fx,fy;             //start/finish
int ans;                     //answer

int go[4][2]=
{
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
};

void dfs(int x, int y)
{
    if(x==fx&&y==fy)
    {
        ans++;
        return;
    }
    
    for(int i=0;i<4;i++)
    {
        int _x=x+go[i][0];
        int _y=y+go[i][1];
        if((_x>0&&_x<=n)&&(_y>0&&_y<=m)&&(!vis[_x][_y])&&(!bar[_x][_y]))
        {
            vis[_x][_y]=1;
            dfs(_x, _y);
            vis[_x][_y]=0;
        }
    }
}

int main()
{
    cin>>n>>m>>t;
    cin>>sx>>sy>>fx>>fy;
    for(int i=1;i<=t;i++)
    {
        int __X,__Y;
        cin>>__X>>__Y;
        bar[__X][__Y]=1;
    }
    dfs(sx, sy);
    cout<<ans;
}