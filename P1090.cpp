#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(int &a, int &b)
{
    return a<b;
}

int main()
{
    int n,a[10050],b[10050];
    int ans;
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n,cmp);
    b[0]=a[0];
    for(int i=1;i<n;i++)
    {
        b[i]=(b[i-1]+a[i]);
    }
    for(int i=1;i<n;i++)
        ans+=b[i];
    cout<<ans;
    return 0;
}