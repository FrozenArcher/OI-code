#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

int main()
{
    stack <char> s;
    char x;
    while((x=getchar())!='@')
    {
        if(x=='(') s.push(x);
        else if(x==')')
        {
            if(s.top()=='(') s.pop();
            else s.push(')');
        }
    }
    if(s.empty()) cout<<"YES";
    else cout<<"NO";
    return 0;
}