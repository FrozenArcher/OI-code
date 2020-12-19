#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct contest
{
    int id,sco;
}c[5050];

bool cmp(contest a,contest b)
{
    return a.sco==b.sco?a.id<b.id:a.sco>b.sco;
}

int main()
{
    int n,m,scl,sclp;//m:total people,n:selected people,scl:line,sclp:second people
    cin>>n;
    cin>>m;
    sclp=m*1.5;
    for(int i=1;i<=n;i++)
    scanf("%d%d",&c[i].id,&c[i].sco);
    sort(c+1,c+n+1,cmp);
    scl=c[sclp].sco;
    for(int i=sclp;c[i].sco==c[i+1].sco;i++)
    sclp++;
    cout<<scl<<' '<<sclp<<endl;
    for(int i=1;i<=sclp;i++)
    cout<<c[i].id<<' '<<c[i].sco<<endl;
    return 0;
}