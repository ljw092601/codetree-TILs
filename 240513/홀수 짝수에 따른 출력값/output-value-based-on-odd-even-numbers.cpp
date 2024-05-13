#include <iostream>
using namespace std;

int sum_n(int n) {
    if(n==1) return 1;
    if(n==2) return 2;
    return sum_n(n-2) + n;
}

int main() {
    int n;
    cin >> n;
    cout << sum_n(n);
    return 0;
}