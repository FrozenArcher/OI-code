#include <iostream>
int main() {
    int n, h[20] = {1, 1};
    std::cin >> n;
    for (int i=2; i<=n; i++)
        for (int j=0; j < i; j++)
            h[i] += h[j] * h[i - j - 1];
    std::cout << h[n];
    return 0;
}