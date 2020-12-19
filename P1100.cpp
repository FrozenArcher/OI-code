#include <iostream>
int main() {
    unsigned x;
    std::cin >> x;
    std::cout << ((x & 0x0000ffff) << 16 | (x & 0xffff0000) >> 16) << std::endl;
}
