#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct stu
{
    int num,chi,tot;
}s[305];

bool cmp(stu &s1, stu &s2)
{
    if(s1.tot!=s2.tot) return s1.tot>s2.tot;
    if(s1.chi!=s2.chi) return s1.chi>s2.chi;
    return s1.num<s2.num;
}

int n;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        s[i].num=i+1;
        int c,m,e;
        scanf("%d %d %d",&c,&m,&e);
        s[i].chi=c;
        s[i].tot=c+m+e;
    }
    sort(s,s+n,cmp);
    for(int i=0;i<5;i++)
    {
        printf("%d %d",s[i].num,s[i].tot);
        puts("");
    }
    return 0;
}