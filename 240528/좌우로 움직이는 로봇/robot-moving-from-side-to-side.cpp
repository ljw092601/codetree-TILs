#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> move_a;
    vector<int> move_b;
    int crr_a = 0, crr_b = 0;
    while(n--) {
        char dir;
        int dist;
        cin >> dist >> dir;
        if (dir == 'R') {
            while(dist--) {
                crr_a++;
                move_a.push_back(crr_a);
            }
        }
        else {
            while(dist--) {
                crr_a--;
                move_a.push_back(crr_a);
            }
        }
    }
    while(m--) {
        char dir;
        int dist;
        cin >> dist >> dir;
        if (dir == 'R') {
            while(dist--) {
                crr_b++;
                move_b.push_back(crr_b);
            }
        }
        else {
            while(dist--) {
                crr_b--;
                move_b.push_back(crr_b);
            }
        }
    }
    while(move_a.size() < move_b.size()) {
        move_a.push_back(crr_a);
    }
    while(move_a.size() > move_b.size()) {
        move_b.push_back(crr_b);
    }
    int meet = 0;
    for (int i=1; i<move_a.size(); i++) {
        if(move_a[i-1] != move_b[i-1] && move_a[i] == move_b[i]) {
            meet++;
        }
    }
    cout << meet;
    return 0;
}