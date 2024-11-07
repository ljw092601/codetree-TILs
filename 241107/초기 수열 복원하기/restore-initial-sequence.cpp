#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool possible(const vector<int>& v, int n) {
    set<int> v_set;
    for (int i : v) {
        if (n < i) return false;
        if (v_set.find(i) != v_set.end()) {
            return false;
        }
        v_set.insert(i);
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> sum_vec(n-1);
    for (int i=0; i<n-1; i++) {
        cin >> sum_vec[i];
    }

    vector<int> n_vec(n);

    for (int i=0; i<n; i++) {
        n_vec[i] = 1;
        int p = 1;
        while(0 <= i-p) {
            n_vec[i-p] = sum_vec[i-p] - n_vec[i-p+1];
            p++;
        }
        p = 1;
        while(i+p < n) {
            n_vec[i+p] = sum_vec[i+p-1] - n_vec[i+p-1];
            p++;
        }
        if (possible(n_vec, n)) {
            for (int k : n_vec) {
                cout << k << " ";
            }
            return 0;
        }
    }

    return 0;
}