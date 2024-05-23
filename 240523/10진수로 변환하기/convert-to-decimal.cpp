#include <iostream>
#include <cmath>
using namespace std;

int n_to_decimal (int n, int nums) {
    int decimal = 0;
    int temp = nums;
    for(int i=0; pow(10, i)<=nums; i++) {
        decimal += (temp%10) * pow(n, i);
        temp /= 10;
    }
    return decimal;
}

int main() {
    int n;
    cin >> n;
    cout << n_to_decimal(2, n);
    return 0;
}