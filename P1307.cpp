#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin>>s;
    if(s[0]=='-')
    {
        cout<<'-';
        s[0]=' ';
    }
    if(s[s.length()]== 
    for(int i=s.length()-1;i!=0;i--)
    cout<<s[i];
    else
    for(int i=s.length()-2;i!=0;i--)
    cout<<s[i];
    return 0;
}