#include <iostream>

int arr(int n) {
    if(n==1) return 1;
    if(n==2) return 2;
    return arr(n/3) + arr(n-1);
}

int main() {
    int n;
    std::cin >> n;
    std::cout << arr(n);
    return 0;
}