#include<iostream>
#include<cstdio>
#include<vector>
#define MAXN 10010
using namespace std;

struct carpet
{
    int fx, fy, tx, ty;
    carpet(int _x, int _y, int _g, int _k)
    {
        fx = _x;
        fy = _y;
        tx = _x+_g;
        ty = _y+_k;
    }
};
vector <carpet> v;
int n, x, y, ans = -1;

int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int _x, _y, _g, _k;
        scanf("%d%d%d%d", &_x, &_y, &_g, &_k);
        v.push_back(carpet(_x, _y, _g, _k));
    }
    cin>>x>>y;
    for(int i=0; i<v.size(); i++)
        if((x>=v[i].fx)&&(x<=v[i].tx)&&(y>=v[i].fy)&&(y<=v[i].ty))
            ans = i+1;
    cout<<ans;
    return 0;
}
