#include<iostream>
using namespace std;

int k[105];
int n;

int main()
{
    cin>>n;
    for(int i=n;i>=0;i--)
    cin>>k[i];
    for(int i=n;i>=0;i--)
    {
        if(k[i]==0) continue;

        if(i==n)
        if(k[i]<0) cout<<'-';
        else if(k[i]>0) ;

        if(i!=n)
        if(k[i]>0) cout<<'+';
        else if(k[i]<0) cout<<'-';

        if((k[i]>0&&k[i]!=1)||(i==0)) cout<<k[i];
        else if((k[i]<0&&k[i]!=-1)||i==0) cout<<-1*k[i];

        if(i==1) cout<<"x";
        else if(i==0) ;
        else cout<<"x^"<<i;
    }
    return 0;
}