#include <iostream>
using namespace std;

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    int min = (a*24*60 + b*60 + c) - (11*24*60 + 11*60 + 11);
    cout << ((min >= 0) ? min : -1);
    return 0;
}