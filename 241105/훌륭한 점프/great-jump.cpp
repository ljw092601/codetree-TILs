#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for (int i=0; i<n; i++) {
        cin >> vec[i];
    }
    auto min_max = minmax_element(vec.begin(), vec.end());
    int min_vec = *min_max.first;
    int max_vec = *min_max.second;

    for (int i=(vec[0] < vec[n] ? vec[n] : vec[0]); i<=max_vec; i++) {
        int jump = 0;
        bool fail = false;
        for (int v : vec) {
            if (v <= i) {
                if (jump > k) {
                    fail = true;
                    break;
                }
                jump = 0;
            }
            jump++;
        }
        if (!fail && jump <= k) {
            cout << i;
            return 0;
        }
    }
    return 0;
}