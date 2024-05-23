#include <iostream>
using namespace std;

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    cout << (a*24*60 + b*60 + c) - (11*24*60 + 11*60 + 11);
    return 0;
}