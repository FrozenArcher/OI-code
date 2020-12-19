#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAXN 20005
using namespace std;

typedef long long LL;

LL a[MAXN];
int n,c;

int main()
{
    cin>>n>>c;
    for(int i=0;i<n;i++)
    scanf("%lld",&a[i]);
    sort(a,a+n);
    LL ans=0;
    int i=0,L_BD=0,U_BD=0;
    while(i<n)
    {
        while(L_BD<n && a[L_BD]< a[i]+c)
        L_BD++;
        while(U_BD<n && a[U_BD]<=a[i]+c)
        U_BD++;
        ans+=U_BD-L_BD;
        i++;
    }
    printf("%lld",ans);
    return 0;
}