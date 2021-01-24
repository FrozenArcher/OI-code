// 堆 模板
/*
#include <iostream>
#include <algorithm>
#define MAXN 100010
using namespace std;

int heap[MAXN];
int size, n, op, num;

void insert(int n)
{
    int now, next;
    heap[++size] = n;
    now = size;
    while (now > 1)
    {
        next = now >> 1;
        if (heap[now] >= heap[next])
            return;
        swap(heap[now], heap[next]);
        now = next;
    }
}

int get_top()
{
    return heap[1];
}

int pop()
{
    int now, next, res;
    res = heap[1];
    heap[1] = heap[size--];
    now = 1;
    while (now * 2 <= size)
    {
        next = now * 2;
        if (next < size && heap[next + 1] < heap[next])
            next++;
        if (heap[now] <= heap[next])
            return res;
        swap(heap[now], heap[next]);
        now = next;
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> op;
        switch (op)
        {
        case 1:
        {
            cin >> num;
            insert(num);
            break;
        }

        case 2:
        {
            cout << get_top();
            break;
        }

        case 3:
        {
            pop();
            break;
        }

        default:
            break;
        }
    }
    return 0;
}*/
#include <queue>
#include <cstdio>
using namespace std;

int main()
{
    priority_queue <int, vector<int>, greater<int> > q;
    int n, opr, x;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &opr);
        if (opr == 1)
        {
            scanf("%d", &x);
            q.push(x);
        }
        else if (opr == 2)
            printf("%d\n", q.top());
        else
            q.pop();
    }
}
