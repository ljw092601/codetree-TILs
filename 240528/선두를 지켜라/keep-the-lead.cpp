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
    bool a_is_faster;
    if (move_a[0] > move_b[0]) a_is_faster = true;
    else a_is_faster = false;
    for (int i=0; i<move_a.size(); i++) {
        if (a_is_faster) {
            if(move_a[i] < move_b[i]) {
                change++;
                a_is_faster = false;
            }
        }
        else {
            if(move_a[i] > move_b[i]) {
                change++;
                a_is_faster = true;
            }
        }
    }
    cout << change;
    return 0;
}