#include <iostream>
using namespace std;

int sum_each_n(int n) {
    if (n<10) return n;
    return sum_each_n(n/10) + n%10;
}

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    cout << sum_each_n(a*b*c);
    return 0;
}