#include <iostream>
using namespace std;

int arr(int n) {
    if (n==1) return 2;
    if (n==2) return 4;
    return (arr(n-1) * arr(n-2)) % 100;
}

int main() {
    int n;
    cin >> n;
    cout << arr(n);
    return 0;
}