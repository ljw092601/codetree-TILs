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

    int max_num = 0;
    for (int i=min_vec; i<max_vec; i++) {
        int num = 0;
        for (int v : vec) if (i <= v && v <= i+k) num++;
        if (max_num < num) max_num = num;
    }
    cout << max_num;
    return 0;
}