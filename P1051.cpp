#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;

int n,tot;

struct stu
{
    string name;
    int jxj;
    int num;
}s[105];

bool cmp(stu & s1, stu & s2)
{
    if(s1.jxj==s2.jxj) return s1.num<s2.num;
    return s1.jxj>s2.jxj;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        s[i].num=i+1;
        int qm,bj,lw;
        bool gb=0,xb=0;
        char _g,_x;
        cin>>s[i].name>>qm>>bj>>_g>>_x>>lw;
        if(_g=='Y') gb=1;
        if(_x=='Y') xb=1;
        if(lw&&qm>80) {s[i].jxj+=8000;tot+=8000;}
        if(qm>85&&bj>80) {s[i].jxj+=4000;tot+=4000;}
        if(qm>90) {s[i].jxj+=2000;tot+=2000;}
        if(xb&&qm>85) {s[i].jxj+=1000;tot+=1000;}
        if(gb&&bj>80) {s[i].jxj+=850;tot+=850;}
    }
    sort(s,s+n,cmp);
    cout<<s[0].name<<endl;
    cout<<s[0].jxj<<endl;
    cout<<tot;
    return 0;
}