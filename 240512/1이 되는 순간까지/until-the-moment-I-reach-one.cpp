#include <iostream>
using namespace std;

int count_div(int n) {
    if (n==1) return 0;
    if(n%2==0) return count_div(n/2) + 1;
    if(n%2==1) return count_div(n/3) + 1;
}

int main() {
    int n;
    cin >> n;
    cout << count_div(n);
    return 0;
}