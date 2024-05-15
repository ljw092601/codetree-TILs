#include <iostream>
using namespace std;

int count_3n(int n) {
    static int count = 0;
    if (n==1) return count;
    count++;
    if (n%2 == 0) return count_3n(n / 2);
    else return count_3n(3 * n + 1);
}

int main() {
    int n;
    cin >> n;
    cout << count_3n(n);
    return 0;
}