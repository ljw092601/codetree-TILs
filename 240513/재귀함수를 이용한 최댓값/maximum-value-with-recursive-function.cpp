#include <iostream>
using namespace std;

int max_n(int n) {
    int num;
    cin >> num;
    if(n==1) return num;
    int pre_n = max_n(n-1);
    if (pre_n <= num) return num;
    else return pre_n;
}

int main() {
    int n;
    cin >> n;
    cout << max_n(n);
    return 0;
}