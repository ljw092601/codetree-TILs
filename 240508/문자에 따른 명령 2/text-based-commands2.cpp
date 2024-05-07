#include <iostream>
#include <string>
using namespace std;

int main() {
    int x = 0; int y = 0;
    int dx[4] = {0, -1,  0, 1};
    int dy[4] = {1,  0, -1, 0};
    int direct = 100000;
    string command;
    cin >> command;
    for (char c: command) {
        if (c == 'L') direct++;
        else if (c == 'R') direct--;
        else if (c == 'F') {
            x += dx[direct%4];
            y += dy[direct%4];
        }
    }
    cout << x << " " << y;
    return 0;
}