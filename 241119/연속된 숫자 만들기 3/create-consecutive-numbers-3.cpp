#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (b-a == 1 && c-b == 1) cout << 0;
    else if (b-a == 2 && c-b == 2) cout << 1;
    else {
        if (b-a <= c-b) cout << c-b-1;
        else cout << b-a-1;
    }
    return 0;
}