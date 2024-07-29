#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x1_vec(n,0);
    vector<int> x2_vec(n,0);
    for(int i=0; i<n; i++) {
        cin >> x1_vec[i] >> x2_vec[i];
    }
    vector<bool> cross_line(n, false);
    for(int i=0; i<n-1; i++) {
        for(int p=i+1; p<n; p++) {
            if((x1_vec[i] - x1_vec[p]) * (x2_vec[i] - x2_vec[p]) < 0) {
                cross_line[i] = true;
                cross_line[p] = true;
            }
        }
    }
    int non_cross = 0;
    for (bool c : cross_line) {
        if (!c) non_cross++;
    }
    cout << non_cross;
    return 0;
}