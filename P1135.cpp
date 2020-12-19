#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;

struct lift
{
    lift(){}
    lift(int f, int t)
    {FLR_NOW = f; time = t;}
    int FLR_NOW;
    int time;
};

int N,A,B;
int k[205];
bool vis[205];
queue <lift> q;
int ans;

bool check(lift x)
{
    if(x.FLR_NOW>N||x.FLR_NOW<=0) return 0;
    if(vis[x.FLR_NOW]) return 0;
    return 1;
}

int main()
{
    cin>>N>>A>>B;
    for(int i=1;i<=N;i++)
    cin>>k[i];
    
    lift L0(A,0);
    q.push(L0);
    vis[A]=1;
    
    while (!q.empty())
    {
        lift l=q.front();
        q.pop();
        int FN=l.FLR_NOW;
        
        if(FN==B)
        {
            ans=l.time;
            break;
        }

        lift l1(FN+k[FN],l.time+1);
        lift l2(FN-k[FN],l.time+1);
        if(check(l1)) 
        {
            q.push(l1);
            vis[l1.FLR_NOW]=1;
        }
        if(check(l2))
        {
            q.push(l2);
            vis[l2.FLR_NOW]=1;
        }
    }
    
    if(vis[B]) printf("%d",ans);
    else printf("-1");
    
    return 0;
}