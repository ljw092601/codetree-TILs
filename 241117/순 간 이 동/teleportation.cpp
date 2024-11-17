#include <iostream>
using namespace std;

int main() {
    int a,b,x,y;
    cin >> a >> b >> x >> y;
    int min = abs(b - a);
    if (min > abs(x-a) + abs(b-y)) min = abs(x-a) + abs(b-y);
    if (min > abs(x-b) + abs(a-y)) min = abs(x-b) + abs(a-y);
    cout << min;
    return 0;
}