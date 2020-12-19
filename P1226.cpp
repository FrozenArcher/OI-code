#include<iostream>
#include<cstdio>
using namespace std;

typedef unsigned long long ull;
ull b,p,mod,a;

ull pow(ull d,ull m)
{
    ull ans=1,base=d;
    while(m>0)
    {
        if(m & 1) ans=(ans*base)%mod;
        base*=base;
        m>>=1;
    }
    return ans;
}

int main()
{
    cin>>b>>p>>mod;
    a=(pow(b,p))%mod;
    cout<<b<<'^'<<p<<" mod "<<mod<<'='<<a;
    return 0;
}