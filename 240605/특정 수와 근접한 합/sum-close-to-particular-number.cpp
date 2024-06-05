#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    vector<int> n_vec(n, 0);
    for (int i=0; i<n; i++) {
        cin >> n_vec[i];
    }
    int min_diff = INT_MAX;
    for (int i=0; i<n-1; i++) {
        for (int p=i+1; p<n; p++) {
            int sum = 0;
            for (int num : n_vec) {
                if (num != n_vec[i] && num != n_vec[p]) sum += num;
            }
            int diff = abs(sum - s);
            if (diff < min_diff) min_diff = diff;
        }
    }
    cout << min_diff;

    return 0;
}