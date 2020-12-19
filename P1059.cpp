#include<iostream>
#include<algorithm>
using namespace std;

int n,cnt=0;
int a[101];
bool flag[101];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(!flag[x])
        {
            a[cnt]=x;
            flag[x]=1;
            cnt++;
        }
    }
    sort(a,a+cnt);
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++)
    cout<<a[i]<<" ";
    return 0;
}