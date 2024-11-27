#include <iostream>
using namespace std;

void cal_function(int *a, int *b) {
    if (*a > *b) {
        *a *= 2;
        *b += 10;
    }
    else {
        *a += 10;
        *b *= 2;
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    cal_function(&a,&b);
    cout << a << " " << b;

    return 0;
}