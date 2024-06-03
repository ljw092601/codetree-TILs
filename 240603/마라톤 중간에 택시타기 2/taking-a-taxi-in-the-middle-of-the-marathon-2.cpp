#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

vector<int> check_x;
vector<int> check_y;

int cale_d(int idx1, int idx2) {
    return abs(check_x[idx1] - check_x[idx2]) + abs(check_y[idx1] - check_y[idx2]);
}

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        check_x.push_back(x);
        check_y.push_back(y);
    }
    int min_dist = INT_MAX;
    for (int i=1; i<n-1; i++) {
        int dist = 0;
        for (int p=0; p<n-1; p++) {
            if(p+1 == i) {
                dist += cale_d(p, p+2);
            }
            else if(p == i);
            else {
                dist += cale_d(p, p+1);
            }
        }
        if(dist < min_dist) min_dist = dist;
    }
    cout << min_dist;
    return 0;
}