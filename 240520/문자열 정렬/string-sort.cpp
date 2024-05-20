#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string name;
    cin >> name;
    sort(name.begin(), name.end());
    cout << name;
    return 0;
}