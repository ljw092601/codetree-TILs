#include <iostream>
using namespace std;

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    if (abs(a-b) == 1 && abs(b-c) == 1) cout << 0;
    else if(abs(a-b) == 2 && abs(b-c) == 2) cout << 1;
    else cout << 2;
    return 0;
}