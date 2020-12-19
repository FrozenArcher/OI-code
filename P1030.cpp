#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

string pos, mid;

void make(int lp, int rp, int lm, int rm)
{
    for (int i = rm; i >= lm; i--)
    {
        if (mid[i] == pos[rp])
        {
            cout << mid[i];
            make(lp, rp - (rm - i) - 1, lm, i - 1);
            make(rp - (rm - i), rp - 1, i + 1, rm);
        }
    }
}

int main()
{
    cin >> mid;
    cin >> pos;
    mid = " " + mid;
    pos = " " + pos;
    make(1, pos.length() - 1, 1, mid.length() - 1);
    return 0;
}
