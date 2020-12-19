#include<iostream>
#include<cstdio>
using namespace std;

double a,b,c,d;

double f(double n)
{
    return a*n*n*n+b*n*n+c*n+d;
}

void search(double l, double r)
{
    if(r-l<=0.001)
    {
        printf("%.2lf ",l);
        return;
    }
    double mid=(l+r)/2;
    if(f(mid)==0) printf("%.2lf ",mid);
    if(f(r)==0) printf("%.2lf ",r);
    if(f(l)*f(mid)<0) search(l,mid);
    else
    if(f(mid)*f(r)<0) search(mid,r);
}

int main()
{
    cin>>a>>b>>c>>d;
    for(double i=-100.0;i<=99.0;i++)
        if(f(i)*f(i+1.0)<=0)
        search(i,i+1.0);
    return 0;
}