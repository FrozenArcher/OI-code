#include<iostream>
#include<string>
using namespace std;

string s;
int a[100];

int main()
{
    int tmp,cnt=1,x=0;
    cin>>s;

    for(int i=0;i<s.length()-1;i++)
    {
        if(s[i]!='-'){
        x+=(s[i]-'0')*cnt;
        cnt++;
        }
    }

    x%=11;
    int l=s[s.length()-1]-'0';
    if(l==x) cout<<"Right";
    else if(x==10 && s[s.length()-1]=='X')
    cout<<"Right";
    else
    {
        if(x==10) s[s.length()-1]='X';
        else{
        char c=(x+'0');
        s[s.length()-1]=c;
        }
        cout<<s;
    }

    return 0;
}