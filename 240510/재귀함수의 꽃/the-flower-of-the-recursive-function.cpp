#include <iostream>
using namespace std;

void down_and_up(int n) {
    if(n == 0) return;
    cout << n << " ";
    down_and_up(n-1);
    cout << n << " ";
}

int main() {
    int n;
    cin >> n;
    down_and_up(n);
    return 0;
}