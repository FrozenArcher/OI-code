#include <iostream>
using namespace std;
int i_2_o(char a)
{
    if (a == 'A')
        return 10;
    if (a == 'B')
        return 11;
    if (a == 'C')
        return 12;
    if (a == 'D')
        return 13;
    if (a == 'E')
        return 14;
    if (a == 'F')
        return 15;
    return int(a - '0');
}
char o_2_i(int a)
{
    if (a == 15)
        return 'F';
    if (a == 14)
        return 'E';
    if (a == 13)
        return 'D';
    if (a == 12)
        return 'C';
    if (a == 11)
        return 'B';
    if (a == 10)
        return 'A';
    return char(a + '0');
}
int main()
{
    long long i, n = 0, p1, p2, x = 1;
    string s, res = "";
    cin >> p1 >> s >> p2;
    for (i = s.size() - 1; i >= 0; i--)
    {
        n += i_2_o(s[i]) * x;
        x *= p1;
    }
    while (n != 0)
    {
        res = o_2_i(n % p2) + res;
        n /= p2;
    }
    cout << res << endl;
    return 0;
}