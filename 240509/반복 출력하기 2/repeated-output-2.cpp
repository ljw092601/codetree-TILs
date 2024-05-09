#include <iostream>
using namespace std;

void print_hello(int n) {
    if(n == 0) return;
    print_hello(n-1);
    cout << "HelloWorld" << endl;
}

int main() {
    int n;
    cin >> n;
    print_hello(n);
    return 0;
}