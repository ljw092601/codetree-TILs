#include <iostream>

void print_star(int n) {
    if(n == 0) return;
    print_star(n-1);
    while (n--) std::cout << "*";
    std::cout << std::endl;
}

int main() {
    int n;
    std::cin >> n;
    print_star(n);
    return 0;
}