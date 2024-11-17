#include <iostream>
using namespace std;

int up_down(int s) {
    int d=0;
    for (int i=1; i<s; i++) {
        d += i;
    }
    return d * 2 + s;
}

int main() {
    int dist;
    cin >> dist;

    int max_spd = 1;
    while(dist - up_down(max_spd) > max_spd)max_spd++;
    cout << max_spd * 2;
    return 0;
}