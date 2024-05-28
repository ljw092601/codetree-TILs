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
        cin >> dir >> dist;
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
        cin >> dir >> dist;
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
    bool meet = false;
    for (int i=0; i<move_a.size(); i++) {
        if(move_a[i] == move_b[i]) {
            meet = true;
            cout << i+1;
            break;
        }
    }
    if (!meet) cout << -1;
    return 0;
}