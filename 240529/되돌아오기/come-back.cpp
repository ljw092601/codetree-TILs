#include <iostream>
using namespace std;

int direction(char d) {
    if(d == 'E') return 0;
    if(d == 'W') return 1;
    if(d == 'S') return 2;
    if(d == 'N') return 3;
}

int main() {
    int arr_x[4] = {1,-1,0,0};
    int arr_y[4] = {0,0,-1,1};
    int n;
    cin >> n;
    int x=0, y=0, time=0;
    bool comeback = false;
    while(n--) {
        int dist;
        char d;
        cin >> d >> dist;
        int dir = direction(d);
        while(dist--) {
            x += arr_x[dir];
            y += arr_y[dir];
            time++;
            if(x==0 && y==0) {
                cout << time;
                comeback = true;
                break;
            }
        }
        if(comeback) break;
    }
    if(!comeback) cout << -1;
    return 0;
}