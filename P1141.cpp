#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

struct point
{
    int x,y;
};

int n,m;
int map[1050][1050];
point ask[100050];
queue <point> q;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>map[i][j];
    for(int i=1;i<=m;i++)
        cin>>ask[i].x>>ask[i].y;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cout<<map[i][j];
    for(int i=1;i<=m;i++)
        cout<<ask[i].x<<ask[i].y;
}