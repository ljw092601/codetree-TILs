#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b < c || d < a) cout << "nonintersecting";
    else cout << "intersecting";
    return 0;
}