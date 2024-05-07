#include <iostream>
using namespace std;

int which_way(char c) {
    if      (c == 'E') return 0;
    else if (c == 'W') return 1;
    else if (c == 'S') return 2;
    else if (c == 'N') return 3;
}

int main() {
    int x=0; int y=0;
    int mov = 0;
    int dx[4] = {1, -1,  0, 0};
    int dy[4] = {0,  0, -1, 1};
    int N;
    cin >> N;
    for (int i=0; i<N; i++) {
        char com;
        int dist;
        cin >> com >> dist;
        mov = which_way(com);
        x += dx[mov] * dist;
        y += dy[mov] * dist;
    }
    cout << x << " " << y;
    return 0;
}