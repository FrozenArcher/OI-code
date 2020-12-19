#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#define  _sort sort(p,p+n,cmp);
using namespace std;

int e[12],n,k;

struct person
{
    int w;
    int num;
    int d;
}p[20010];

int cmp(const person &a,const person &b)
{
    if(a.w!=b.w)
    return a.w>b.w;
    return a.num<b.num; 
}

int main()
{
    cin>>n>>k;
    for(int i=0;i<10;i++)
    scanf("%d",&e[i]);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&p[i].w);
        p[i].num=i+1;
    }
    _sort
    for(int i=0;i<n;i++)
    {
        p[i].d=i%10;
        p[i].w+=e[p[i].d];
    }
    _sort
    for(int i=0;i<k;i++)
    printf("%d ",p[i].num);
    return 0;
}
//by frozenarcher