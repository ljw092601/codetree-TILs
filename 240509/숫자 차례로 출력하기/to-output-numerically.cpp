#include <iostream>
using namespace std;

void ascending_print(int n) {
    if (n == 0) return;
    ascending_print(n-1);
    cout << n << " ";
}

void decending_print(int n) {
    if (n == 0) return;
    cout << n << " ";
    decending_print(n-1);
}

int main() {
    int n;
    cin >> n;
    ascending_print(n);
    cout << endl;
    decending_print(n);
    return 0;
}