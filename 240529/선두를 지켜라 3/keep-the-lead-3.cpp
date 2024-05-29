#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> move_a;
    vector<int> move_b;
    int crr_a = 0, crr_b = 0, crr_ta = 0, crr_tb = 0;
    while(n--) {
        int v, t;
        cin >> v >> t;
        for (int i=crr_ta; i<crr_ta+t; i++) {
            crr_a += v;
            move_a.push_back(crr_a);
        }
        crr_ta += t;
    }
    while(m--) {
        int v, t;
        cin >> v >> t;
        for (int i=crr_tb; i<crr_tb+t; i++) {
            crr_b += v;
            move_b.push_back(crr_b);
        }
        crr_tb += t;
    }
    int change = 0;
    int faster = 0; //0:same, 1:a is faster 2: b is faster
    int crr_faster;
    for (int i=0; i<move_a.size(); i++) {
        if(move_a[i] < move_b[i]) crr_faster = 2;
        else if (move_a[i] > move_b[i]) crr_faster = 1;
        else crr_faster = 0;
        if (faster != crr_faster) {
            change++;
            faster = crr_faster;
        }
    }
    cout << change;
    return 0;
}