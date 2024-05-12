#include <iostream>
using namespace std;

int sum_squ(int n) {
    if(n<10) return n*n;
    return sum_squ(n/10) +(n%10) * (n%10);
}

int main() {
    int n;
    cin >> n;
    cout << sum_squ(n);
    return 0;
}