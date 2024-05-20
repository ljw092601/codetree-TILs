#include <iostream>
using namespace std;

int GCD(int a, int b) {
    for (int i=2; i<=a; i++) {
        if (a%i==0 && b%i==0) return i;
    }
    return 1;
}

int LCM(int a, int b) {
    return a*b/GCD(a,b);
}

int get_LCMs(int n) {
    int new_n;
    cin >> new_n;
    if (n==1) return new_n;
    return LCM(new_n, get_LCMs(n-1));
}

int main() {
    int n;
    cin >> n;
    cout << get_LCMs(n);
    return 0;
}