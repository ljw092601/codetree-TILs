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
    while(up_down(max_spd) > dist || dist > up_down(max_spd+1))max_spd++;
    if (dist - up_down(max_spd) > max_spd) cout <<  max_spd * 2 + 1;
    else if(dist - up_down(max_spd) > 0) cout <<  max_spd * 2;
    else cout << max_spd * 2 - 1;
    return 0;
}