#include<iostream>
#include<algorithm>
#include<string>
#define MAXN 25
using namespace std;

string s[MAXN];
int n;

bool cmp(string &s1, string &s2)
{
    return s1+s2 > s2+s1;
}

int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>s[i];
    sort(s, s+n, cmp);
    for(int i=0; i<n; i++)
        cout<<s[i];
    return 0;
}
