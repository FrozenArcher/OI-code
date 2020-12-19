#include<iostream>
using namespace std;
int n,ans=1;
int f[1100];
int main()
{
    cin>>n;
    f[0]=f[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(i%2==0) f[i]=f[i-1]+f[i/2];
        else f[i]=f[i-1];
    }
    cout<<f[n];
}