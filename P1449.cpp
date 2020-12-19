#include<iostream>
#include<cstdio>
#include<stack>

using namespace std;

stack <int> s;
int num=0,x,y;

int main()
{
    char c;
    do
    {
        c=getchar();
        if(c>='0'&&c<='9')
        {
            int x=c-'0';
            num=num*10+x;
        }
        else if(c=='.')
        {
            s.push(num);
            num=0;
        }
        else if(c!='@')
        {
            x=s.top();s.pop();y=s.top();s.pop();
            switch(c)
            {
                case '+':s.push(x+y); break;
                case '-':s.push(y-x); break;
                case '*':s.push(x*y); break;
                case '/':s.push(y/x); break;
            }
        }
    }while(c!='@');
    printf("%d\n",s.top());
    return 0;
}