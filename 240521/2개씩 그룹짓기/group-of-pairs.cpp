#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    n *= 2;
    vector<int> n_vec;
    while(n--) {
        int num;
        cin >> num;
        n_vec.push_back(num);
    }
    sort(n_vec.begin(), n_vec.end());
    auto last = n_vec.end()-1;
    int max = 0;
    for (auto i = n_vec.begin(); i < last; i++) {
        if (max < *i + *last) max = *i + *last;
        last--;
    }
    cout << max;
    return 0;
}